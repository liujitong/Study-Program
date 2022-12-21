clc;

%Canon IXUS 60 (fine)
 Cannon = [1 1 1 2 3 6 8 10 
          1 1 2 3 4 8 9 8 
          2 2 2 3 6 8 10 8 
          2 2 3 4 7 12 11 9 
          3 3 8 11 10 16 15 11 
          3 5 8 10 12 15 16 13 
          7 10 11 12 15 17 17 14 
          14 13 13 15 15 14 14 14];
 %Nikon CoolPix L12 (fine)
 Nikon = [2 1 1 2 3 5 6 7 
          1 1 2 2 3 7 7 7  
          2 2 2 3 5 7 8 7 
          2 2 3 3 6 10 10 7 
          2 3 4 7 8 13 12 9 
          3 4 7 8 10 12 14 11 
          6 8 9 10 12 15 14 12 
          9 11 11 12 13 12 12 12]; 
%Jpeg Standard
Q=[16 11 10 16 24 40 51 61
   12 12 14 19 26 58 60 55
   14 13 16 24 40 57 69 56
   14 17 22 29 51 87 80 62
   18 22 37 56 68 109 103 77
   24 35 55 64 81 104 113 92
   49 64 78 87 103 121 120 101
   72 92 95 98 112 100 103 99];
test = [];
for i=1:8
    x=[];
    for j=1:8
         x=[x 1.5^(i+j-2)];
    end
    test=[test x'];
end
test

RGB = imread('test.bmp');
GR = rgb2gray(RGB);
[av p] =exp_quantization(GR,test,['test_','test'])
[av p] =exp_quantization(GR,Cannon,['test_','Cannon'])
[av p] =exp_quantization(GR,Nikon,['test_','Nikon'])
[av p] =exp_quantization(GR,Q,['test_','Q'])


RGB = imread('lena.bmp');
GR = rgb2gray(RGB);


%Partition it into 8*8 blocks
ps=[];
for a=0.1:0.1:2
    [av p] =exp_quantization(GR,a*test,[num2str(a),'test']);
    fprintf(' av_psnr %f  ',av);
    fprintf('all psnr %f\n',p);
    ps=[ps p];
end
%plot(0.1:0.1:2,ps);
x=0.1:0.1:2;
y=ps;
xi = 0.1:0.01:2;
yi=interp1(x,y,xi,'cubic');
figure(4);
plot(xi,yi,':',x,y,'o');
set(gcf,'color','w');


%Partition it into 8*8 blocks
ps=[];
for a=0.1:0.1:2
    [av p] =exp_quantization(GR,a*Q,[num2str(a),'Q']);
    fprintf(' av_psnr %f  ',av);
    fprintf('all psnr %f\n',p);
    ps=[ps p];
end
%plot(0.1:0.1:2,ps);
x=0.1:0.1:2;
y=ps;
xi = 0.1:0.01:2;
yi=interp1(x,y,xi,'cubic');
figure(1);
plot(xi,yi,':',x,y,'o');
set(gcf,'color','w');



ps=[];
for a=0.1:0.1:2
    [av p] =exp_quantization(GR,a*Nikon,[num2str(a),'Nikon']);
    fprintf(' av_psnr %f  ',av);
    fprintf('all psnr %f\n',p);
    ps=[ps p];
end
%plot(0.1:0.1:2,ps);
x=0.1:0.1:2;
y=ps;
xi = 0.1:0.01:2;
yi=interp1(x,y,xi,'cubic');
figure(2)
plot(xi,yi,':',x,y,'o');
set(gcf,'color','w');

ps=[];
for a=0.1:0.1:2
    [av p] =exp_quantization(GR,a*Cannon,[num2str(a),'Cannon']);
    fprintf(' av_psnr %f  ',av);
    fprintf('all psnr %f\n',p);
    ps=[ps p];
end
%plot(0.1:0.1:2,ps);
x=0.1:0.1:2;
y=ps;
xi = 0.1:0.01:2;
yi=interp1(x,y,xi,'cubic');
figure(3)
plot(xi,yi,':',x,y,'o');
set(gcf,'color','w');

