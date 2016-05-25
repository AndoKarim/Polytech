//Question 1
[s,fe] = wavread('signal');
N = length(s);

//Question 2 
R = 512;
spectre = fft(s(1:R)); //On prend les N premiers échantillons
f=[0:1:R-1]*fe/R;
plot2d(f,abs(spectre)/R);

//Question 3
M=4;
sd=s(1:M:length(s));
feM = fe/M;
fM =[0:R-1]*feM/R;
signal = abs(fft(sd(1:R)))/R;
figure(2);
plot2d(fM,signal);

//Question 4 

sse = zeros(1,length(s));
sse(1:M:length(s))=sd;
t=[0:length(s)-1]/fe;
figure(3);
plot2d(t,sse,-4,rect=[0,-0.5,0.1,0.5]);

//Question 5.a
R=512;
fe=8000;
//h2 rectangulaire
H2 = 4*[zeros(1,R/8),ones(1,R/8+1),zeros(1,R/2-1),ones(1,R/8+1),zeros(1,R/8-1)];

//h2 arrondi
H2aa=[zeros(1,R/8-1),0.1,0.5,0.9,ones(1,R/8-3),0.9,0.5,0.1,zeros(1,R/2-3),0.1,0.5,0.9,ones(1,R/8-3),0.9,0.5,0.1,zeros(1,R/8-2)];
h2 = fftshift(real(ifft(H2aa)));


//Question 5.b
t2=[0:R-1]/fe;
figure(4);
plot2d(t2,h2);

//Question 5.d
H = abs(fft(h2));
Hm=abs(fft([h2,zeros(1,15*R)]));
fM = [0:16*R-1]*fe/(16*R);
figure(5);
plot2d(fM,Hm);


sdecompr = convol(h2,sse);
sp=abs(fft(s(1:R)));
fftw_forget_wisdom();
spd = abs(fft(sdecompr(1:R)));
f=[0:R-1]*fe/R;
figure(6);
plot2d(f,sp);
