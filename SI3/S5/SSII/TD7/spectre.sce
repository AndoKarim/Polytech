function spectre(s,fe,nom)
//% calcule le spectre d'amplitude du signal s
//% on prend une fenêtre rectangulaire de N=length(s) échantillons
//% la fréquence d'échantillonnage vaut fe
N=length(s);
fr=[0:N-1]*fe/N;
spe=abs(fft(s));
M=max(spe);
plot2d3(fr,spe)
xrect([0,0,fe,M+.0001])
ylabel(nom)
xlabel('fréquence (en Hz)')
xtitle(['abs(fft(',nom,')),',string(N),' points'])
xgrid
