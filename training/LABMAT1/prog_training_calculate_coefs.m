%
clear all
close all
addpath(genpath('../../mcode-libs'))

DATAPRINT.LINEWIDTH=2;
DATAPRINT.FONTSIZE=26;
DATAPRINT.MARKERSIZE=4;

INPUT_FILENAME_COLOR="/home/fernando/Dropbox/Cafe-Arbusto/WorkGroup1/data/imagen1.bmp";
INPUT_FILENAME_BW="/home/fernando/Dropbox/Cafe-Arbusto/WorkGroup1/data-bw/imagen1.bmp.bw.bmp";

OUTPUT_DIR="output-training";
OUPUT_FILENAME_COEFS="plane_coef.dat";

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
PARTS=10;
EPSILON=0.00005;

IMG_COLOR = double(imread(INPUT_FILENAME_COLOR));   %% RGB IMAGE
IMG_BW    = double(imread(INPUT_FILENAME_BW));      %% 0 GOOD : 1 BAD

rand("seed",8.1485e-312);

C=func_calculate_plane2(IMG_COLOR,IMG_BW,PARTS,EPSILON,DATAPRINT) %% 3D Plane
save("-ascii",fullfile(OUTPUT_DIR,OUPUT_FILENAME_COEFS),"C")

print(gcf,fullfile(OUTPUT_DIR,"plane_coef.eps"),'-depsc',['-F:' num2str(DATAPRINT.FONTSIZE)]);


IMG_GRAY=plot_grayscale_results(IMG_COLOR,C,DATAPRINT);
print(gcf,fullfile(OUTPUT_DIR,"sigmoid_result.eps"),'-depsc','-tight',['-F:' num2str(round(0.8*DATAPRINT.FONTSIZE))]);

%imagesc(IMG_GRAY>0.8)
%colormap(gray)

