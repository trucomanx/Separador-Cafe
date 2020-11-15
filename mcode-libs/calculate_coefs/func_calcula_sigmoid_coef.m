function [CC ERROR2]=func_calcula_sigmoid_coef( POINT_COLOR_GOOD,
                                                POINT_COLOR_BAD,
                                                PERCENT_ERROR,
                                                COEF_INIT)
    alpha=0.5;
    
    B=[ ones(size(POINT_COLOR_GOOD,1),1); ...
        zeros(size(POINT_COLOR_BAD,1),1)];

    C{1}=COEF_INIT';   
    
    for KK=1:100

        FF=[    fun_f(POINT_COLOR_GOOD,C{KK}); ...
                fun_f(POINT_COLOR_BAD ,C{KK})];

        JJ=[    fun_Df(POINT_COLOR_GOOD,C{KK}); ...
                fun_Df(POINT_COLOR_BAD ,C{KK})];

        C{KK+1}=C{KK}-inv(JJ'*JJ+alpha*eye(4))*JJ'*(FF-B);

        PERROR=norm(C{KK}-C{KK+1})/norm(C{KK+1});

        print_error(B,KK,POINT_COLOR_GOOD,POINT_COLOR_BAD,C{KK+1},PERROR);%%% Print data in screen

        if (PERROR*100)<PERCENT_ERROR
            break
        endif
    endfor

    fprintf(stdout,"\n",KK)

    CC=C{end}';
    FF=[    fun_f(POINT_COLOR_GOOD,CC); ...
            fun_f(POINT_COLOR_BAD ,CC)];
    ERROR2=norm(FF-B)^2;

endfunction




function print_error(B,KK,POINT_COLOR_GOOD,POINT_COLOR_BAD,C,PERROR)

    FF=[    fun_f(POINT_COLOR_GOOD,C); ...
            fun_f(POINT_COLOR_BAD ,C)];
    ERROR2=norm(FF-B)^2;

    fprintf(stdout,
            "NPOINTS: %6d\tITER: %3d\tPERR: %6.2f%c\tERR2: %5.1f\tC: %s        \r",
            length(B),
            KK,
            100*PERROR,
            37,
            ERROR2,
            mat2str(C,2));
endfunction

