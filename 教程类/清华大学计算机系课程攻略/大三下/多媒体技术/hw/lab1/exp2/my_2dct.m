function [ y ] = my_2dct( x , Q )
    % ʹ��blkproc�Ծ�����зֿ飬�����д����xΪ8*8�ľ���(�ܹ������4096��)��QΪ��������
    global sum;
    % ���ȶ�8*8�ľ������2D-dct�仯
    D2_dct = dct2(x);
    % Ȼ���2D-dct�Ľ������������������ʽ�ο� http://bbs.csdn.net/topics/310026388
    temp = round(D2_dct ./ Q);
    % ��������2D-idctʱ����Ҫ����������������õ���PSNRֵ���С��ͼƬ���Ǻڵ�
    D2_idct = idct2(temp .* Q);
    y = D2_idct;
    % ����ÿ��8*8�����PSNR�������浽Q_1_data.txt�ļ���
    psnr_ans = my_psnr(y , x);
%     fid = fopen('Q_1_data.txt' , 'a');
%     fprintf(fid , '\n' , psnr_ans);
%     fclose(fid);
    % ��¼�ܹ���PSNR�����ڼ����ֵ
    sum = sum  + psnr_ans;
end

