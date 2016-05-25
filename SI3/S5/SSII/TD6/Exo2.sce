[s,fe] = wavread('signal2');
N = length(s);

R = 512;
spectre = fft(s(1:R)); //On prend les N premiers échantillons
f=[0:1:R-1]*fe/R;
plot2d(f,abs(spectre)/R);
