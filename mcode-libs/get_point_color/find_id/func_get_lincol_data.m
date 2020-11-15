function [DATA_GOOD DATA_BAD]=func_get_lincol_data(IMG)
    IMG=round(IMG);

    [BAD_LIN BAD_COL]=find(IMG==0);

    [GOOD_LIN GOOD_COL]=find(IMG);

    DATA_GOOD=[GOOD_LIN GOOD_COL];
    DATA_BAD =[BAD_LIN  BAD_COL];
endfunction
