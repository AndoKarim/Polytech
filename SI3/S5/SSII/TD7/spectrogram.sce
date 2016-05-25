function [spectre]=spectrogram(y,D,fe)
  // fenêtre de hamming
  hamming=window('hm',D);
  // calcul du spectre
    spectre=[];
    N=fix(length(y)/D)-1; //nbre de fenêtres
    for k= 1:N
      debut=1+(k-1)*D;
      spe=1+abs(fft(y(debut:debut+D-1).*hamming));
      spectre=[spectre;20*log10(spe(1:D/2)/D)];
  end
   fr=[0:D/2-1]*fe/D;
   t=(0:N-1)*D/fe;
   clf();
   //xset("colormap",autumncolormap(64))
      xset("colormap",graycolormap(64))
   colorbar(min(spectre),0)
   grayplot(t',fr',spectre)
   xtitle(["Spectrogramme fenêtre de taille: ",string(D)])
   xlabel('temps (s)')
   ylabel('fréquence (Hz)')
 endfunction
