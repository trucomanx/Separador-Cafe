%%%
close all 

DAT.MARKERSIZE=12;
DAT.FONTSIZE=24;
DAT.LINEWIDTH=3;

function resp=istriangle(a,b,c)
    resp1= a + b > c;
    resp2= a + c > b;
    resp3= b + c > a;
    resp=(resp1 + resp2 + resp3)==3;  
endfunction

ta = tb = tc = logspace (log10(0.01), log10(1), 20)';
[aa, bb, cc] = meshgrid (ta, tb,tc);
AA=aa(:);
BB=bb(:);
CC=cc(:);
SS=(AA+BB+CC)/2;
GAMMA = (AA+BB+CC)./(SS.*(SS-AA).*(SS-BB).*(SS-CC)).^(1/4);

IDWORNG=find(istriangle(AA,BB,CC)==0);
AA(IDWORNG)=[];
BB(IDWORNG)=[];
CC(IDWORNG)=[];
GAMMA(IDWORNG)=[];

scatter3 (AA,BB,CC,[], log10(GAMMA));
view([136.45 23.690])
colormap(jet)
hcb=colorbar;
colorTitleHandle = get(hcb,'Title');
set(colorTitleHandle ,'String','log_{10}(\gamma_t)');
set (colorTitleHandle, "fontsize", DAT.FONTSIZE);

hx=xlabel('a');
set (hx, "fontsize", DAT.FONTSIZE);
hy=ylabel('b');
set (hy, "fontsize", DAT.FONTSIZE);
hz=zlabel('c');
set (hz, "fontsize", DAT.FONTSIZE);
set (gca, "fontsize", DAT.FONTSIZE);

print(gcf,'section1-gammat.eps','-depsc',['-F:' num2str(DAT.FONTSIZE)])
