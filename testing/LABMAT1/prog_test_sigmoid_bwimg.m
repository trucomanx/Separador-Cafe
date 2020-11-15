%
clear all
%close all
addpath(genpath('../../mcode-libs'))

INPUT_FILENAME_COLOR="/home/fernando/Dropbox/Cafe-Arbusto/WorkGroup1/data/imagen1.bmp";
INPUT_FILENAME_COEFS="data/plane_coef.dat";

OUTPUT_DIR="output-test";

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [IMG_COLOR, IMG_GRAY, IMG_BW]=get_images(  INPUT_FILENAME_COLOR,
                                                    INPUT_FILENAME_COEFS,
                                                    UMBRAL)

    IMG_COLOR=imread(INPUT_FILENAME_COLOR);      %% RGB IMAGE
    ID=[1:(size(IMG_COLOR,1)*size(IMG_COLOR,2))];

    C=load(INPUT_FILENAME_COEFS);

    NLIN=size(IMG_COLOR,1);
    NCOL=size(IMG_COLOR,2);
    IMG_GRAY=zeros(NLIN,NCOL);
    IMG_BW=zeros(NLIN,NCOL);


    P=double(reshape(IMG_COLOR,[NLIN*NCOL 3]));
    P_BW=fun_f(P,C);

    IMG_GRAY(:)=P_BW;
    imagesc(IMG_GRAY)
    colormap(jet)
    colorbar

    IMG_BW=IMG_GRAY>=UMBRAL;
    %figure(2)
    %imagesc(IMG_BW)
    %colormap(gray)

endfunction

figure(1)
[IMG_COLOR, IMG_GRAY, IMG_BW]=get_images(   INPUT_FILENAME_COLOR,
                                            INPUT_FILENAME_COEFS,
                                            0.8);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Binary image segmetation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% %% disp('CUMULOS ON')
% %% C = Cumulus(IMG_BW);
% %% [MAP ID WID]= C.calculate_cumulus();
% %% disp('CUMULOS OFF')

% Elimina cumulos menores a 100 pixels
pkg load image
IMG_BW_CLEAN= bwareaopen (IMG_BW, 625);
figure(2)
imagesc(IMG_BW_CLEAN)
colormap(gray)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

stats = regionprops(IMG_BW_CLEAN,'Centroid','Area','Perimeter','Boundingbox');
confirm_recursive_rmdir(false)
rmdir(OUTPUT_DIR, "s");
mkdir(OUTPUT_DIR);
mkdir(fullfile(OUTPUT_DIR,'TIPO1'));
mkdir(fullfile(OUTPUT_DIR,'TIPO2'));


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% CALCULO GAMMA e area media
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
GAMMA=zeros(length(stats),1);
JJ=1;
for II=1:length(stats)
    GAMMA(II)=stats(II).Perimeter/sqrt(stats(II).Area);
    if (GAMMA(II)<4)
        AREA(JJ)=stats(II).Area;
        JJ=JJ+1;
    end
endfor
COFFE_MEAN_AREA=mean(AREA)
COFFE_STD_AREA=std(AREA)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% MOSTRANDO FACTOR  AREA/COFFE_MEAN_AREA
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure(3)
image(IMG_COLOR)
for II=1:length(stats)
    
    thisBB = round(stats(II).BoundingBox);
    if (GAMMA(II)<4)
        rectangle(  'Position', ...
                    thisBB, %[thisBB(1),thisBB(2),thisBB(3),thisBB(4)], ...
                    'EdgeColor','r','LineWidth',3 );

        LINS=thisBB(2):(thisBB(2)+thisBB(4)-1);
        COLS=thisBB(1):(thisBB(1)+thisBB(3)-1);
        RECT_IMG=IMG_COLOR( LINS, COLS, :);
        imwrite(RECT_IMG,fullfile(OUTPUT_DIR,'TIPO1',sprintf("rect%d.bmp",II)));
    else
        rectangle(  'Position', ...
                    thisBB, %[thisBB(1),thisBB(2),thisBB(3),thisBB(4)], ...
                    'EdgeColor','g','LineWidth',3 );

        LINS=thisBB(2):(thisBB(2)+thisBB(4)-1);
        COLS=thisBB(1):(thisBB(1)+thisBB(3)-1);
        RECT_IMG=IMG_COLOR( LINS, COLS, :);
        imwrite(RECT_IMG,fullfile(OUTPUT_DIR,'TIPO2',sprintf("rect%d.bmp",II)));
    endif

    STRING=sprintf("%4.1f",stats(II).Area/COFFE_MEAN_AREA);
    text (thisBB(1)+thisBB(3)/2,thisBB(2)+thisBB(4)/2, STRING,"color", "white","horizontalalignment", "center","fontsize",20);    


endfor
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% MOSTRANDO FACTOR  AREA/COFFE_MEAN_AREA
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure(4)
% image(IMG_COLOR)
imagesc(IMG_GRAY)
colormap(gray)
for II=1:length(stats)
    
    thisBB = round(stats(II).BoundingBox);
    if (GAMMA(II)<4)
        rectangle(  'Position', ...
                    thisBB, %[thisBB(1),thisBB(2),thisBB(3),thisBB(4)], ...
                    'EdgeColor','r','LineWidth',3 );
    else
        rectangle(  'Position', ...
                    thisBB, %[thisBB(1),thisBB(2),thisBB(3),thisBB(4)], ...
                    'EdgeColor','g','LineWidth',3 );
    endif

    STRING=sprintf("%4.1f",GAMMA(II));
    text (thisBB(1)+thisBB(3)/2,thisBB(2)+thisBB(4)/2, STRING,"color", "red","horizontalalignment", "center","fontsize",20);    
endfor
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


