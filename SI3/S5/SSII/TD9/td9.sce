[s,fe,B] = wavread('piano');
N = length(s);
M=4;
R=256;
exec('bancfiltres.sce');
[s,hh,B,fe]=bancfiltres(M,R,'piano.wav',1);
t=[0:1:N-1]*fe/R;

//Sous échantillonner 
sd1=s(1,1:M:length(s(1,:)));
h1=hh(1,:);
sd2=s(2,1:M:length(s(2,:)));
h2=hh(2,:);
sd3=s(3,1:M:length(s(3,:)));
h3=hh(3,:);
sd4=s(4,1:M:length(s(4,:)));
h4=hh(4,:);


//Sur-échantillonner
sdsh1 = zeros(1,N);
sdsh1(1,1:M:N)=sd1;

sdsh2 = zeros(1,N);
sdsh2(1,1:M:N)=sd2;

sdsh3 = zeros(1,N);
sdsh3(1,1:M:N)=sd3;

sdsh4 = zeros(1,N);
sdsh4(1,1:M:N)=sd4;


sfiltre1=convol(sdsh1,hh(1,:));
sfiltre2=convol(sdsh2,hh(2,:));
sfiltre3=convol(sdsh3,hh(3,:));
sfiltre4=convol(sdsh4,hh(4,:));

srec1 = sfiltre1(1+R/2:N+R/2);
srec2 = sfiltre2(1+R/2:N+R/2);
srec3 = sfiltre3(1+R/2:N+R/2);
srec4 = sfiltre4(1+R/2:N+R/2);

sdec = srec1+srec2+srec3+srec4;


