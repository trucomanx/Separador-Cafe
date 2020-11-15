%% avalia pontos o conjunto de pontos
function ff=fun_f(P,C)
    ARG=P(:,1)*C(1)+P(:,2)*C(2)+P(:,3)*C(3)+C(4);
    ff=1.0./(1.0+exp(-ARG));
endfunction

