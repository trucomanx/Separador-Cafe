function IMG_GRAY=plot_grayscale_results(IMG_COLOR,C,DATAPRINT)

    NLIN=size(IMG_COLOR,1);
    NCOL=size(IMG_COLOR,2);
    IMG_GRAY=zeros(NLIN,NCOL);

    P=double(reshape(IMG_COLOR,[NLIN*NCOL 3]));
    P_BW=fun_f(P,C);

    IMG_GRAY(:)=P_BW;

    figure(1)
    imagesc(IMG_GRAY)
    colormap(jet)
    hc=colorbar;
    daspect([1 1 1])
    
    colorTitleHandle = get(hc,'Title');
    titleString = 'y';
    set(colorTitleHandle ,'String',titleString);
    set(colorTitleHandle ,'fontsize',round(DATAPRINT.FONTSIZE));

    set(gca,'xtick',[])
    set(gca,'ytick',[])

    set(hc,'fontsize',round(DATAPRINT.FONTSIZE))
    set(gca,'fontsize',round(DATAPRINT.FONTSIZE))
    
endfunction

function ff=fun_f(P,C)
    ARG=P(:,1)*C(1)+P(:,2)*C(2)+P(:,3)*C(3)+C(4);
    ff=1.0./(1.0+exp(-ARG));
endfunction

