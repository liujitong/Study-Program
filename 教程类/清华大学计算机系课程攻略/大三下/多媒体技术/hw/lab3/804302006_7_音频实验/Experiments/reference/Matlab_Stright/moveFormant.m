function adjustedSpec = moveFormant(src,tgt,percentage)

%�ҳ�Ӧ���ƶ��ĳ̶�
srcformant=markformant(src);
tgtformant=markformant(tgt);

len_x0=length(srcformant(1,:));
len_x1=length(tgtformant(1,:));

%������СΪһ����


%��ʼѭ��

%����������������ֵ:
maxsrc=max(max(srcformant));
maxtgt=max(max(tgtformant));

adjustedSpec=zeros(length(srcformant(:,1)),len_x0);

for i=1:len_x0
    %formant position of current source frame
    [valuesrc,possrc]=max(srcformant(:,i));
    [valuetgt,postgt]=max(tgtformant(:,i));    
    if valuesrc*10>maxsrc&&valuetgt*10>maxtgt
        adjustedSpec(:,i)=moveFrameFormant(src(:,i),possrc,postgt,percentage);
    end
end

return; 