%ʹ��FFT�����߾��
function res = conv_circle(a, b)
m = length(a);
n = length(b);
a=[a,zeros(1,n-1)];     %�����г��Ȳ�Ϊn+m-1
b=[b,zeros(1,m-1)];
aa=fft(a);              %����FFT
bb=fft(b);
y = aa .* bb;
res=ifft(y);           %����IFFT
end

