%yoΪ���������ź�
%yΪ�丵��Ҷ����, mseΪ�������
% hΪ���ߣ�wΪ����nΪ����
function [y, yo, mse] = rect(h, w, n, x)
T = 2 * w; %����
yo = h * rectpuls(x, w);
y = h * w / T;
for k = 1:n
    y = y + ((2 * h * w * sin(k * pi * w / T) / (k * pi)) * cos(k * 2 * pi * x / T));
end
mse = norm(y - yo);