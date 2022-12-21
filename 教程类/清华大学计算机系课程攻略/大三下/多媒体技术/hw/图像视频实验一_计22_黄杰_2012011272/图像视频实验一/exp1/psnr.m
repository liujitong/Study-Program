%% functionname: function description
function [PSNR] = psnr(img, imgn)
    img=double(img);
    imgn=double(imgn);
    [h w]=size(img);
    B=8;                %����һ�������ö��ٶ�����λ
    MAX=2^B-1;          %ͼ���ж��ٻҶȼ�
    MES=sum(sum((img-imgn).^2))/(h*w);     %������
    PSNR=20*log10(MAX/sqrt(MES));           %��ֵ�����
end
