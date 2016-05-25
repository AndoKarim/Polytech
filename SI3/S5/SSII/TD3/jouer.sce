function s=jouer(a0,f0,D,fe)
    t=[0:1/fe:D];
    s=a0*cos(2*%pi*f0*t);
endfunction
