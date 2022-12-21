%Goertzel�㷨
function res = Goertzel(fileName)
res = 0;
keys = ...
['1','2','3','A';
'4','5','6','B';
'7','8','9','C';
'*','0','#','D'];			%�����Ų�
[y, fs] = audioread(fileName); 	
N = length(y);
x = y(1:N);					%��ȡ�ʵ�ʱ��?
tic 						%��ʼ��ʱ
temp = zeros(1,N);
dtmf = [697, 770, 852, 941, 1209, 1336, 1477, 1633]; %dtmf����8��Ƶ��	
k = N / fs * dtmf;								%8��Ƶ�ʶ�Ӧ�������еĵ�
P = zeros(1,8);
for m = 1:8
	fil = 2 * cos(2*pi*k(m)/N);									%�˲�
	for i = 3:N-3
		temp(i) = fil .* temp(i-1) - temp(i-2) + x(i);			%Goertzel�㷨����
	end
	P(m)=temp(N-3).^2 + temp(N-4).^2 - fil*temp(N-3)*temp(N-4);		%���㹦��
end
P = abs(P);
col = find(P(5:8) == max(P(5:8)));  %�ҵ���
row = find(P(1:4) == max(P(1:4)));  %�ҵ���
res = keys(row, col);			%�ҵ���Ӧ����
toc         
end
