function [C ERROR]=func_calcula_logit_coef(POINT_COLOR_GOOD,POINT_COLOR_BAD,PROB_ERRO)

    P=[ POINT_COLOR_GOOD; ...
        POINT_COLOR_BAD];

    N_GOOD=size(POINT_COLOR_GOOD,1);
    N_BAD=size(POINT_COLOR_BAD,1);

    
    PROB=[ (1.0-PROB_ERRO)*ones(N_GOOD,1); ...
               (PROB_ERRO)*ones(N_BAD,1)];

    R=log(PROB./(1.0-PROB));

    A=[P, ones(size(R))];

    C=inv(A'*A)*A'*R;

    ERROR=(A*C-R)'*(A*C-R)/length(R);

    C=C';
endfunction
