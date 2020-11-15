%%%
close all 

DAT.MARKERSIZE=12;
DAT.FONTSIZE=24;
DAT.LINEWIDTH=3;

ta = tb = logspace (log10(0.01), log10(1), 40)';
[aa, bb] = meshgrid (ta, tb);
GAMMA = 2*(aa+bb)./sqrt (aa.*bb);

surf (aa,bb,log10(GAMMA));
view([136.45 23.690])
colormap(jet)

hx=xlabel('a');
set (hx, "fontsize", DAT.FONTSIZE);
hy=ylabel('b');
set (hy, "fontsize", DAT.FONTSIZE);
hz=zlabel('log_{10}(\gamma_r)');
set (hz, "fontsize", DAT.FONTSIZE);
set (gca, "fontsize", DAT.FONTSIZE);

print(gcf,'section1-gammar.eps','-depsc',['-F:' num2str(DAT.FONTSIZE)])
