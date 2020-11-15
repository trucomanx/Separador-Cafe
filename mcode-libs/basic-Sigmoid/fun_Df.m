function Df=fun_Df(P,C)
    Df=fun_f(P,C).*(1-fun_f(P,C)).*[P(:,1) P(:,2) P(:,3) ones(size(P(:,3)))];
endfunction
