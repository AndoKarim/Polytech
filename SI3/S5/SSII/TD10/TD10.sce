Im = imread('images/baboon.png');
//maxRouge=max(Im(:,:,1))
//minRouge=min(Im(:,:,1))
//maxVert=max(Im(:,:,2))
//minVert=min(Im(:,:,2))
//maxBleu=max(Im(:,:,3))
//minBleu=min(Im(:,:,3))
size(Im)
imshow(Im);
Img = rgb2gray(Im);
imshow(Img);

r=Im;
r(:,:,[2,3])=0;
r=rgb2gray(r);
imshow(r);

g=Im;
g(:,:,[1,3])=0;
g=rgb2gray(g);
imshow(g);

b=Im;
b(:,:,[1,2])=0;
b=rgb2gray(b);
imshow(b);


bar(imhist(Img),1,'red');

///////////////////////////////
////Traitement image Y (luminance)
//////////////////////////////
Yimg = imread('images/YBaboon.png');
imshow(imadd(Yimg,100))
bar(imhist(Yimg),1,'red');
median(double(Yimg))
stdev(double(Yimg))

function Z=contraste(X,t)
    n=size(X,1);
    p=size(X,2);
    Z=double(X);
    b=median(Z);
    M(1:n,1:p)=b;
    Z=M+t*(Z-M);
    M(:)=255;Z=min(Z,M);M(:)=0; Z=max(Z,M);
    Z=uint8(Z);
endfunctiondcqf


