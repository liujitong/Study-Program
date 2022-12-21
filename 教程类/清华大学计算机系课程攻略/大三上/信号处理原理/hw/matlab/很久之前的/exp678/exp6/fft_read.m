%FFT�㷨
function res = fft_read(filename)
[audio, fs] = audioread(filename);
tic
y = abs(fft(audio,fs));       %fft
p = y;               
dtmf = [697, 770, 852, 941, 1209, 1336, 1477, 1633]; %dtmf����8��Ƶ��	
row = find(p(650:1000) == max(p(650:1000))) + 649;  %��һ����ֵ      
col = 1149 + find(p(1150:1500) == max(p(1150:1500)));  %�ڶ�����ֵ
rf = abs(dtmf - row);           %����׼Ƶ������
cf = abs(dtmf - col);
row = find(rf == min(rf));      %�����ӽ���һ��
col = find(cf == min(cf)) - 4;  %�����ӽ���һ��

keys = ...
    ['1','2','3','A';
    '4','5','6','B';
    '7','8','9','C';
    '*','0','#','D'];
res = keys(row,col);
toc
end
