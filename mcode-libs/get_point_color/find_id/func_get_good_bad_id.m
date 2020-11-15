function [GOOD_ID BAD_ID]=func_get_good_bad_id(IMG)
    IMG=round(IMG);

    [GOOD_ID]=find(IMG);

    [BAD_ID]=find(IMG==0);
endfunction
