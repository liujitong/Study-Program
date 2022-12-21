global sum; % ȫ�ֱ���sum������������8*8���PSNR�ľ�ֵ
sum = 0.0;
Q = [16 11 10 16 24 40 51 61 % ��������Q
     12 12 14 19 26 58 60 55
     14 13 16 24 40 57 69 56
     14 17 22 29 51 87 80 62
     18 22 37 56 68 109 103 77
     24 35 55 64 81 104 113 92
     49 64 78 87 103 121 120 101
     72 92 95 98 112 100 103 99];
 
Cannon = [1 1 1 2 3 6 8 10 
          1 1 2 3 4 8 9 8 
          2 2 2 3 6 8 10 8 
          2 2 3 4 7 12 11 9 
          3 3 8 11 10 16 15 11 
          3 5 8 10 12 15 16 13 
          7 10 11 12 15 17 17 14 
          14 13 13 15 15 14 14 14];
 
Nikon = [2 1 1 2 3 5 6 7 
         1 1 2 2 3 7 7 7  
         2 2 2 3 5 7 8 7 
         2 2 3 3 6 10 10 7 
         2 3 4 7 8 13 12 9 
         3 4 7 8 10 12 14 11 
         6 8 9 10 12 15 14 12 
         9 11 11 12 13 12 12 12];

my_policy = [1 1 1 2 3 6 7 8
             1 1 2 3 5 7 9 8
             2 2 2 3 5 8 10 12
             2 2 3 4 6 9 12 12
             3 3 4 8 9 10 11 12
             4 4 5 8 10 12 13 14
             6 8 9 10 12 13 14 15
             9 11 12 13 14 15 16 17];
             

% ����ԭʼͼƬ
img = imread('lena.bmp');

% ת��Ϊ�ҶȲ����
gray = rgb2gray(img);
imwrite(gray , 'gray-lena.bmp');
psnr_gray = im2double(gray);
%�Ժ�������ͼƬ�ֿ飬����ÿ��8*8��С�����dct��������idct������PSNRֵ
I2 = blkproc(gray , [8 8] , @my_2dct , Q);
real_pic = mat2gray(I2); % ע�⣬���Ҫ�ٴ�ת��Ϊ�Ҷȣ��տ�ʼû�ӣ�һֱ�Ǵ�ģ�
disp('ʹ��QΪ��������PSNR��ֵΪ��')
disp(sum / 4096);
imwrite(real_pic , 'Q.bmp');


% ����Jpeg Standard Q������ϵ��a������PSNR����ͼ
x = [];
y = [];
count = 0;
for a = 0.1 : 0.1 : 2
    tempQ = a .* Q;
    sum = 0.0;
    Block8_D2_dct = gray;
    I2 = blkproc(Block8_D2_dct , [8 8] , @my_2dct , tempQ);
%    real_pic = mat2gray(I2);
%    imwrite(real_pic , ['Q_',num2str(a),'_idct.bmp']);
    ans = sum / 4096;
    count = count + 1;
    x(count) = a;
    y(count) = ans;
end
disp(y);
figure('NumberTitle', 'off', 'Name', 'QΪ��������PSNR-a����');
plot(x , y);

% ����Canon IXUS 60 ������ϵ��a������PSNR����ͼ
x = [];
y = [];
count = 0;
for a = 0.1 : 0.1 : 2
    tempCannon = a .* Cannon;
    sum = 0.0;
    Block8_D2_dct = gray;
    I2 = blkproc(Block8_D2_dct , [8 8] , @my_2dct , tempCannon);
%    real_pic = mat2gray(I2);
%    imwrite(real_pic , ['Cannon_',num2str(a),'_idct.bmp']);
    ans = sum / 4096;
    count = count + 1;
    x(count) = a;
    y(count) = ans;
end
disp(y);
figure('NumberTitle', 'off', 'Name', 'CannonΪ��������PSNR-a����');
plot(x , y);

% ����Nikon CoolPix L12 ������ϵ��a������PSNR����ͼ
x = [];
y = [];
count = 0;
for a = 0.1 : 0.1 : 2
    tempNikon = a .* Nikon;
    sum = 0.0;
    Block8_D2_dct = gray;
    I2 = blkproc(Block8_D2_dct , [8 8] , @my_2dct , tempNikon);
    %real_pic = mat2gray(I2);
    %imwrite(real_pic , ['Nikon_',num2str(a),'_idct.bmp']);
    ans = sum / 4096;
    count = count + 1;
    x(count) = a;
    y(count) = ans;
end
disp(y);
figure('NumberTitle', 'off', 'Name', 'NikonΪ��������PSNR-a����');
plot(x , y);

%�����Լ���Ƶ��������� ������ϵ��a������PSNR����ͼ
x = [];
y = [];
count = 0;
for a = 0.1 : 0.1 : 2
    tempmy = a .* my_policy;
    sum = 0.0;
    Block8_D2_dct = gray;
    I2 = blkproc(Block8_D2_dct , [8 8] , @my_2dct , tempmy);
    ans = sum / 4096;
    count = count + 1;
    x(count) = a;
    y(count) = ans;
end
disp(y);
figure('NumberTitle', 'off', 'Name', '�Լ�ʵ�ֵ���������PSNR-a����');
plot(x , y);

% ʹ��Cannon��Nikon�����Լ���ͼƬ��������PSNR
img1 = imread('shoot.bmp');
gray1 = rgb2gray(img1);

gray2 = imread('boat.bmp');

gray3 = imread('barbara.bmp');

% ͼƬ1��shoot.bmp
I2 = blkproc(gray1 , [8 8] , @my_2dct , Cannon);
real_pic = mat2gray(I2); % ע�⣬���Ҫ�ٴ�ת��Ϊ�Ҷȣ��տ�ʼû�ӣ�һֱ�Ǵ�ģ�
disp('ͼƬ1:shoot.bmp��ʹ��CannonΪ��������PSNR��ֵΪ��')
disp(sum / 4096);
imwrite(real_pic , 'shoot_cannon.bmp');

I2 = blkproc(gray1 , [8 8] , @my_2dct , Nikon);
real_pic = mat2gray(I2); % ע�⣬���Ҫ�ٴ�ת��Ϊ�Ҷȣ��տ�ʼû�ӣ�һֱ�Ǵ�ģ�
disp('ͼƬ1:shoot.bmp��ʹ��NikonΪ��������PSNR��ֵΪ��')
disp(sum / 4096);
imwrite(real_pic , 'shoot_Nikon.bmp');

% ͼƬ2��boat.bmp
I2 = blkproc(gray2 , [8 8] , @my_2dct , Cannon);
real_pic = mat2gray(I2); % ע�⣬���Ҫ�ٴ�ת��Ϊ�Ҷȣ��տ�ʼû�ӣ�һֱ�Ǵ�ģ�
disp('ͼƬ2:boat.bmp��ʹ��CannonΪ��������PSNR��ֵΪ��')
disp(sum / 4096);
imwrite(real_pic , 'boat_cannon.bmp');

I2 = blkproc(gray2 , [8 8] , @my_2dct , Nikon);
real_pic = mat2gray(I2); % ע�⣬���Ҫ�ٴ�ת��Ϊ�Ҷȣ��տ�ʼû�ӣ�һֱ�Ǵ�ģ�
disp('ͼƬ2:boat.bmp��ʹ��NikonΪ��������PSNR��ֵΪ��')
disp(sum / 4096);
imwrite(real_pic , 'boat_Nikon.bmp');

% ͼƬ3��barbara.bmp
I2 = blkproc(gray3 , [8 8] , @my_2dct , Cannon);
real_pic = mat2gray(I2); % ע�⣬���Ҫ�ٴ�ת��Ϊ�Ҷȣ��տ�ʼû�ӣ�һֱ�Ǵ�ģ�
disp('ͼƬ3:barbara.bmp��ʹ��CannonΪ��������PSNR��ֵΪ��')
disp(sum / 4096);
imwrite(real_pic , 'barbara_cannon.bmp');

I2 = blkproc(gray3 , [8 8] , @my_2dct , Nikon);
real_pic = mat2gray(I2); % ע�⣬���Ҫ�ٴ�ת��Ϊ�Ҷȣ��տ�ʼû�ӣ�һֱ�Ǵ�ģ�
disp('ͼƬ3:barbara.bmp��ʹ��NikonΪ��������PSNR��ֵΪ��')
disp(sum / 4096);
imwrite(real_pic , 'barbara_Nikon.bmp');
