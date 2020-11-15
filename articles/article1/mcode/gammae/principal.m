%%%
DAT.MARKERSIZE=12;
DAT.FONTSIZE=24;
DAT.LINEWIDTH=3;

ta = tb = logspace (log10(0.01), log10(1), 40)';
[aa, bb] = meshgrid (ta, tb);


AREA=pi*aa.*bb;
PER=zeros(size(AREA));
for II=1:numel(PER)
    str_func=sprintf("4*sqrt((%d)^2-((%d)^2-(%d)^2)*(sin(x))^2)",aa(II),aa(II),bb(II));
    func_temp= inline (str_func);
    PER(II)=quadv (func_temp, 0, pi/2);
endfor


GAMMA = PER./sqrt (AREA);

figure(1)
surf (aa,bb, log10(GAMMA));
view([136.45 23.690])
colormap(jet)


hx=xlabel('a');
set (hx, "fontsize", DAT.FONTSIZE);
hy=ylabel('b');
set (hy, "fontsize", DAT.FONTSIZE);
hz=zlabel('log_{10}(\gamma_e)');
set (hz, "fontsize", DAT.FONTSIZE);
set (gca, "fontsize", DAT.FONTSIZE);

print(gcf,'section1-gammae.eps','-depsc',['-F:' num2str(DAT.FONTSIZE)])

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ta = tb = logspace (log10(0.01), log10(0.1), 40)';
[aa, bb] = meshgrid (ta, tb);


AREA=pi*aa.*bb;
PER=zeros(size(AREA));
for II=1:numel(PER)
    str_func=sprintf("4*sqrt((%d)^2-((%d)^2-(%d)^2)*(sin(x))^2)",aa(II),aa(II),bb(II));
    func_temp= inline (str_func);
    PER(II)=quadv (func_temp, 0, pi/2);
endfor


GAMMA = PER./sqrt (AREA);

figure(2)
surf (aa,bb, abs(4*ones(size(aa))-GAMMA));
view([136.45 23.690])
colormap(jet)


hx=xlabel('a');
set (hx, "fontsize", DAT.FONTSIZE);
hy=ylabel('b');
set (hy, "fontsize", DAT.FONTSIZE);
hz=zlabel('\gamma_e');
set (hz, "fontsize", DAT.FONTSIZE);
set (gca, "fontsize", DAT.FONTSIZE);



