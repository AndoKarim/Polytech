//Exo1
[s,fe,B] = wavread('piano');
N = length(s);
//Q = 2/2^B;
//moy = mean(s);
//ecart = stdev(s);
//t=[0:N-1]/fe;
//
//xstring(0.2,-0.8,["Moyenne = ",string(moy)],0,0);
//xstring(0.2,-0.9,["Ecart type = ",string(ecart)],0,0);
//plot(t,s);
//xmax = max(abs(s));
//u=B-floor(-log(xmax)/log(2))
//
//for i=8:-1:1
//b=i;
//Q=2/(2^b);
//Nq = 2^b
//xbin=floor(s/Q);
//xquant=xbin*Q;
//e=s-xquant;
//SNR=20*log10(ecart/stdev(e));
//C = B/b;
//sound(xquant,fe);
//sleep(1500);
//end

//Exo2
M=4;
R=256;
exec('bancfiltres.sce');
[f,E,Esignal]=bancfiltres(M,R,'piano.wav',1);
t=[0:1:N-1]*fe/R;
figure(1);
s1=f(1,:);
s2=f(2,:);
s3=f(3,:);
s4=f(4,:);
subplot(221)
plot2d(t,s1)
xgrid
xtitle('Signal S1','t(s)','S1')
subplot(222)
plot2d(t,s2)
xgrid
xtitle('Signal S2','t(s)','S2')
subplot(223)
plot2d(t,s3)
xgrid
xtitle('Signal S3','t(s)','S3')
subplot(224)
plot2d(t,s4)
xgrid
xtitle('Signal S4','t(s)','S4')

srec=s1+s2+s3+s4;
figure(3);
subplot(211)
plot2d(t,s);
xtitle('Signal s');
subplot(212)
plot2d(t,srec);
xtitle('Signal srec');
