f = 437.5;
a = 0.5 ; 
fe = 8000;
d=2;
t=[0:1/fe:d];
Tla3 = length(t);
la3 = a*cos(2*f*%pi*t);
//sound(la3,fe);

//Question 1.b

spectre = abs(fft(la3(1:N)))/N;
N=1024;
f=[0:N-1]*fe/N;
plot2d(f,spectre);

//Question 1.c

//Résolution fréquentielle : fe/N
reso = fe/N;
disp(reso);

//On a choisi 437.5Hz pour tomber pile poil sur le maximum vu qu'on 
//calcule une fréquence tous les 7.8125 (reso)

//Question 2.a
M=8;
la3d=la3(1:M:length(la3));
Tla3d = (length(la3d));
//La longueur est 8 fois plus petite 

//Question 2.b
disp(['C=",string(Tla3/Tla3d)])

//Question 2.c
//Nouvelle fréquence = fe /M car la période est multipliée par 8
fed  =fe / M;
disp(fed);
//sound(la3d,fe/M);

Spamp2 = abs(fft(la3d(1:1024)));
f2=[0:1024]*fed/1024

figure(2);
//plot2d(f2,Spamp2);

//Question 3.a 

la3se = zeros(1,length(la3));
la3se(1:M:length(la3)) = la3d;

t=[0:length(la3)-1]/fe;
plot2d(t,la3se,-4,rect=[0,-0.5,0.1,0.5]);

//Question 3.b
f3=[0:1:N-1]*fe/N
figure(3);
plot2d(f3,abs(fft(la3se(1:N)))/N);
length(la3se)       

//sound(la3se,fe)

//Question 4.a
la3Shannon = zeros(1, length(la3));
for j=0 : length(la3d)-1
    la3Shannon = la3Shannon+la3d(j+1)*sinc(%pi * (t-8 *j/fe)*fe/8);
end    
figure(4);
plot2d(t,[la3',la3Shannon' ],rect=[1025/fe,-0.5,1225/fe,0.5]);
legend

//sound(la3Shannon,fe);

