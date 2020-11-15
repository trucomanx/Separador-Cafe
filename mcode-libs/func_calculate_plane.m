function [CMEAN]=func_calculate_plane(DATA_IMG,DATA_BWIMG,PARTS,EPSILON,PERCENT_ERROR)
    
    
    [GOOD_ID BAD_ID]=func_get_good_bad_id(DATA_BWIMG);

    NEL_GOOD=size(GOOD_ID,1);
    NEL_BAD =size(BAD_ID,1);

    N=round(min(NEL_GOOD,NEL_BAD)/PARTS)
    C  =zeros(PARTS,4);
    ERR=zeros(PARTS,1);

    for II=1:PARTS

        N_RAND_GOOD_ID=func_get_n_rand_id(GOOD_ID,N);
        N_RAND_BAD_ID =func_get_n_rand_id(BAD_ID,N);

        POINT_COLOR_GOOD=func_get_color_from_id(DATA_IMG,N_RAND_GOOD_ID);
        POINT_COLOR_BAD =func_get_color_from_id(DATA_IMG,N_RAND_BAD_ID);

        fprintf(stdout,'\n\n');
        % COEF_INIT=func_calcula_linear_coef( POINT_COLOR_GOOD, POINT_COLOR_BAD);
        COEF_INIT=func_calcula_logit_coef(POINT_COLOR_GOOD,POINT_COLOR_BAD,EPSILON)

        [C(II,:) ERR(II)]=func_calcula_sigmoid_coef(POINT_COLOR_GOOD, %%  Posição dos pontos bons
                                                    POINT_COLOR_BAD,  %%  Posição dos pontos ruins
                                                    PERCENT_ERROR,    %%  Error aceitavel em porcentagem
                                                    COEF_INIT);       %%  Coeficiente inicial
        C(II,:)
    endfor

    CMEAN=func_get_mean_vector(C,ERR);

    
    plot_points_and_plane(  N_RAND_GOOD_ID,
                            N_RAND_BAD_ID,
                            CMEAN,
                            DATA_IMG);

endfunction

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function ID=func_get_n_rand_id(DAT_ID,N)
    NTOT=size(DAT_ID,1);
    ID=DAT_ID(round(1+(NTOT-1)*rand(N,1)));
endfunction

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function CMEAN=func_get_mean_vector(C,ERR)
    PARTS=size(C,1);
    NELC=size(C,2);

    CMEAN=zeros(1,NELC);

    for II=1:PARTS
        CMEAN=CMEAN+C(II,:)/ERR(II);
    endfor

    CMEAN=CMEAN/sum(1./ERR);
endfunction
