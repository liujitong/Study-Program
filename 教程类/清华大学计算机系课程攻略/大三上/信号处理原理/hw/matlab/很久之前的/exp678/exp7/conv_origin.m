%ֱ��ʹ�ù�ʽ
function res = conv_origin(a, b)
N=length(a);
M=length(b);
L=M+N-1;
res = zeros(1,L);   %��ʼ��
for n=1:L
    for m=1:M
        k = n-m+1;
        if k >= 1 && k <= N
            res(n) = res(n) + b(m)*a(k);    %�����ʽ���
        end
    end
end
end

