clear all;
%dial����ģ�Ⲧ��
dial('0123456789');
%readDial�ж�������ʲô
res = [];
for i = 0:9
    res = [res,readDial(['dtmf-',num2str(i),'.wav'])];
end
disp(res);