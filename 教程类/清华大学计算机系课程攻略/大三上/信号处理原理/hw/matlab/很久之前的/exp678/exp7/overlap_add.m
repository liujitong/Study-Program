function res = overlap_add(x, h, N)
lx = length(x);
M = length(h);
if N < M        %NӦ��С��M
    N = M + 1;
end
L = N+M-1;
num = ceil(lx/N);  %x���ֳ�num��
temp_y = zeros(1,M-1);
x = [x,zeros(1,(num+1)*N-lx)];
res = zeros(1,(num+1)*N);
for i = 0:num
    left = i*N+1;
    y = ifft(fft(x(left:left+N-1),L) .* fft(h,L));    %����Բ���
    y(1:M-1)= y(1:M-1) + temp_y(1:M-1);                %overlap-add
    temp_y(1:M-1) = y(N+1:L);     %save tail
    res(left:left+N-1) = y(1:N);
end
res = res(1:lx+M-1);
end

