[quisuisje,fe] = wavread('quisuisje.wav');
N=length(quisuisje);  //On peut aussi mettre 1024 pour prendre les 1024 premiers échantillons
spectre = fft(quisuisje(1:N)); //On prend les N premiers échantillons
f=[0:1:N-1]/fe;
//Fenêtre rectangulaire
plot2d(f,abs(spectre)/N);

//On trouve donc :
//s(t)=0.2+0.5*cos(880pi*t) + 0.24 *cos(1600pi*t)+0.12*cos(2200pi*t)

