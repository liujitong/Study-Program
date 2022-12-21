function [ PSNR ] = my_psnr( origin , new )
% ���ݹ�ʽ������PSNR
    origin = double(origin);
    new = double(new);
    mse = sum(sum((origin - new).^2)) / length(origin);
    PSNR = 10 * log10(255 * 255 / mse);
end