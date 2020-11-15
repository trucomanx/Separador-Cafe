%%%
DAT.MARKERSIZE=12;
DAT.FONTSIZE=24;
DAT.LINEWIDTH=3;

rr{1}=1;
II=1;
FATOR=1;
format long
while FATOR>0.000000001
    str_func=sprintf("sqrt(1-(1-(%d)^2)*(sin(x))^2)",rr{II});
    func_temp= inline (str_func);
    rr{II+1}=((quadv (func_temp, 0, pi/2))^2)/pi;
    FATOR=100*abs(rr{II+1}-rr{II})/rr{II+1};
    II=II+1;
end

R=rr{end}
II

N=256;
tx = ty = linspace (-1, 1, N)';
[xx, yy] = meshgrid (tx, ty);
BW=((xx.^2+(yy.^2)/R^2 - 1)<0)*1.0;

L=sqrt(sum(sum(BW)))

imagesc(BW)
colormap(gray)
daspect([1 1 1])

hr=rectangle ( "Position",[ N/2-L/2,N/2-L/2,L,L],
               "EdgeColor",[0.5 0.5 0.5])
set (hr, "linewidth", DAT.LINEWIDTH);

set (gca, "fontsize", DAT.FONTSIZE);

print(gcf,'section1-gammae-square.eps','-depsc','-tight',['-F:' num2str(DAT.FONTSIZE)])



%L=sqrt(pi*R)
%X=linspace(-1,1,100);
%Y=sqrt(R^2-(R^2)*(X.^2));
%plot(X,Y,X,-Y)
%daspect([1 1 1])


