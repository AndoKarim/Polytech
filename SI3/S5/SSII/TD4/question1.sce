x=1; 
fo = 0;
N = 1024; //nombre echantillon
fe=8000; // fréquence d'échantillonnage 
t = [0 : 1 : N-1] /fe ;  //T=[0,1/fe,..(N-1)/fe)]
s=x*cos(2*%pi*fo*t);
plot2d(t,s)
xgrid();
xtitle(["N=",string(N)],"temps(s)","x*cos(2*%pi*fo*t)");

splus=[s,zeros(1,3*N)];
spectre = fft(splus);
spectreAmpl=abs(spectre);
f=[0:1:(N*4)-1]*fe/N*4;
figure(1);
plot2d(f,spectreAmpl);


M = 4*N;
whm = window('hm',N);
sh = s.*whm;
spadd = [sh,zeros(1,M-N)];
t2 = [0 : M-1]*fe/N;
figure(2);

plot2d( f, abs(fft(spadd)));
