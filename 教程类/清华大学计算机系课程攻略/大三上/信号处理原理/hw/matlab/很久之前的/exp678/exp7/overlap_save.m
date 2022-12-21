%ʹ��overlap-save��������
function res = overlap_save(x, h, N)
lx = length(x);
M = length(h);
if N < M          %NӦ��С��M
    N = M + 1;
end
L = N+M-1;
temp_m = zeros(1,M-1);    %xǰ����0
num = ceil(lx/N);     %x���ֳ�num��
x = [x,zeros(1,(num+1)*N-lx)];
res = zeros(1,(num+1)*N);
for i = 0:num
    left = i*N+1;
    temp_x = [temp_m,x(left:left+N-1)]; 
    temp_m = temp_x(N+1:N+M-1);     %����xǰһС��
    temp_y = ifft(fft(temp_x,L) .* fft(h,L)); %����Բ���
    res(left:left+N-1) = temp_y(M:N+M-1);  %�����õĶδ���
end
res = res(1:lx+M-1);
end

