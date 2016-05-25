f =440;
x=1;
N=1024;
fe = 8000;
t=[0:1:N-1]/fe;
s=x*cos(2*%pi*f*t);
plot2d(abs(fft(s))/(N));

t2 = [0:1:(N*3)-1]/fe;
s2=x*cos(2*%pi*f*t2);

splus=[s,zeros(1,3*N)];
figure(1);
plot2d(abs(fft(splus))/(N));
