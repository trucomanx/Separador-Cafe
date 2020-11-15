function P =func_get_color_from_id(DATA_IMG,DAT_ID)
    N=length(DAT_ID);
    P=zeros(N,3);
    SIZE=size(DATA_IMG);

    for II=1:N
        [LIN COL]=ind2sub(SIZE,DAT_ID(II));
        P(II,:)=[DATA_IMG(LIN,COL,1) DATA_IMG(LIN,COL,2) DATA_IMG(LIN,COL,3)];
    endfor
endfunction
