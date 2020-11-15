function C=func_calcula_linear_coef(POINT_COLOR_GOOD,POINT_COLOR_BAD)
    P=[ POINT_COLOR_GOOD; ...
        POINT_COLOR_BAD];

    
    R=[ +ones(size(POINT_COLOR_GOOD,1),1); ...
        -ones(size(POINT_COLOR_BAD,1),1)];
    
    A=[P, ones(size(R))];

    C=inv(A'*A)*A'*R;

    C=C';
endfunction
