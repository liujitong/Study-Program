function adjustedSpecFrame = moveFrameFormant(srcframe,srcformant,tgtformant,percentage)

%�ҳ�Ӧ���ƶ��ĳ̶�
if srcformant==1
    srcformant =2;
end

leftPart = srcframe(1:srcformant);
rightPart = srcframe(srcformant+1:length(srcframe));

newformant = round(srcformant + (tgtformant-srcformant)* percentage);



newleftPart = resample(leftPart,newformant,srcformant);

newrightPart = resample (rightPart,length(srcframe)-newformant,length(srcframe)-srcformant);

adjustedSpecFrame = [newleftPart;newrightPart];

return; 