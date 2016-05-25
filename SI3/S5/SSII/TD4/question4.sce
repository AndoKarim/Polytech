N=128;
x=0.2;
xoo = 0.6;
fe = 8000;
fo = 1500;
fa = 500;
t = [0 : 1 : N-1] /fe ;  //T=[0,1/fe,..(N-1)/fe)]
s=x + x * cos(2 * %pi * fo * t )+ xoo * cos(2 *%pi * fa * t);
plot2d(t,s)
xgrid();

//Spectre d'amplitude de s centré en fe/2

spectre = abs(fft(s));
f=[0:1:N-1]*fe/N;

figure(1);
plot2d(f,spectre/N);
xgrid()

//Spectre d'amplitude de s centré en 0
figure(2);
f2=f-fe/2;
plot2d(f2,fftshift(abs(fft(s)/N)));
xgrid();

//Transformée inverse 
figure(3);
plot2d(t,ifft(spectre))
xgrid();



