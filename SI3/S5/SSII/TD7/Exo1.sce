M = 8;
R = 512;
[y,fe] = wavread('bbc');
Ny = length(y);


//Exo2
N= R/(4*M);
H=[ones(1,N-1),0.9,0.5,0.1,zeros(1,R-2*N-3),0.1,0.5,0.9,ones(1,N-2)];
h=fftshift(real(ifft(H)));
//plot2d(h);

D=R/fe;
figure(2)
f=[0:1:R-1]*fe/R;
plot2d(f,H);

n=0:R-1;
bande=[]
for j=0:M-1
  bande(j+1,:)=2*cos((2*j+1)*n*%pi/(2*M)).*h;
end
size (bande);

s=abs(fft(bande(2,:)));
figure(3)
plot2d(f,s);
