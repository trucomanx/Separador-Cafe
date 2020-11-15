function h=plot_points_and_plane(GOOD_ID,BAD_ID,C,DATA_IMG,DATAPRINT)


    N_GOOD=length(GOOD_ID);
    N_BAD =length(BAD_ID);

    COLOR_R=zeros(N_GOOD+N_BAD,1);
    COLOR_G=zeros(N_GOOD+N_BAD,1);
    COLOR_B=zeros(N_GOOD+N_BAD,1);
    GRUPO  =zeros(N_GOOD+N_BAD,3);

    [LIN_GOOD,COL_GOOD] = ind2sub(size(DATA_IMG),GOOD_ID);
    JJ=1;
    for II=1:N_GOOD
        COLOR_R(JJ)=DATA_IMG(LIN_GOOD(II),COL_GOOD(II),1);
        COLOR_G(JJ)=DATA_IMG(LIN_GOOD(II),COL_GOOD(II),2);
        COLOR_B(JJ)=DATA_IMG(LIN_GOOD(II),COL_GOOD(II),3);
        GRUPO(JJ,:)=[1.0 0 0];
        JJ=JJ+1;
    endfor


    [LIN_BAD,COL_BAD] = ind2sub(size(DATA_IMG),BAD_ID);

    for II=1:N_BAD
        COLOR_R(JJ)=DATA_IMG(LIN_BAD(II),COL_BAD(II),1);
        COLOR_G(JJ)=DATA_IMG(LIN_BAD(II),COL_BAD(II),2);
        COLOR_B(JJ)=DATA_IMG(LIN_BAD(II),COL_BAD(II),3);
        GRUPO(JJ,:)=[0 0 1.0];
        JJ=JJ+1;
    endfor

    

    scatter3(COLOR_R, COLOR_G, COLOR_B, [], GRUPO);
    xlim([0 255])
    ylim([0 255])
    zlim([0 255])
    hx=xlabel('x_1');
    set(hx,'fontsize',DATAPRINT.FONTSIZE);
    hy=ylabel('x_2');
    set(hy,'fontsize',DATAPRINT.FONTSIZE);
    hz=zlabel('x_3');
    set(hz,'fontsize',DATAPRINT.FONTSIZE);

    rr = linspace(0,255,32);
    gg = linspace(0,255,32);
    [RR,GG] = meshgrid(rr,gg);

    BB=-C(1)*RR/C(3)-C(2)*GG/C(3) -C(4)/C(3);
    hold on;
    mesh(RR,GG,BB);
    hold off;

    set(gca,'fontsize',DATAPRINT.FONTSIZE);
    view([-29.299 32.122])
endfunction
