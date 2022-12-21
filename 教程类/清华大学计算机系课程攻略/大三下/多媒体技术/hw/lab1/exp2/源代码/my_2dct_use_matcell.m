function [ y ] = my_2dct_use_matcell( x , Q )
    global sum;
    % ���ڴ����512*512�ľ���ʹ��mat2cell����8*8�ֿ顣
    % mat2cell�ֿ�ο���http://zhidao.baidu.com/question/129455191.html
    origin = mat2cell(x , ones(64 , 1)*8 , ones(64 , 1)*8);
    temp = origin;
    % Ȼ���ÿһ��С�ֿ����2D-DCT�������������� �����õ��Ĺ�ʽ�ο� http://bbs.csdn.net/topics/310026388
    for i = 1 : 64
        for j = 1 : 64 % �ܹ�4096��8*8�ķֿ�
            temp{i , j} = round(dct2(temp{i , j}) ./ Q);
        end
    end
    % Ȼ���ٽ���2D-idct������ԭʼ8*8�ֿ���м���PSNR
    % �ڽ���2D-idct֮ǰ����Ҫ������������õ���ͼƬ�������Ǻڵģ�PSNR��С
    for i = 1 : 64
        for j = 1 : 64
            temp{i , j} = idct2(temp{i , j} .* Q);
            psnr_ans = my_psnr(temp{i , j} , origin{i , j});
            disp(psnr_ans);
            sum = sum + psnr_ans;
        end
    end
    % ����ƽ����PSNR
    psnr_averge = sum / 4096;
    disp('avg:');
    disp (psnr_averge);
    y = psnr_averge;
    % ��ԭ��ԭʼ��512*512�ľ��󣬼�������ͼƬ��PNSRֵ������ԭͼƬ
    big_idct = mat2gray(cell2mat(temp));
    disp('512*512 PSNR:');
    disp(my_psnr(big_idct , x));
    imwrite(big_idct , 'Q.bmp');
    
end

