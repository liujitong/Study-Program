function [peak,peakLeft,peakRight]=findSpecPeak(n3sgramFrame)
        %һ�ε���
        diff1=diff(n3sgramFrame);
        %���ε���
    %    diff2=diff(diff1);
        [peakValue,peak]=max(n3sgramFrame);
        disp(strcat('����at time : ',num2str(peak)));
        peakLeft=peak;
        for j=peak:-1:2
            tempLeft=j;
            if tempLeft>20
                tempLeft=tempLeft-10;
            else
                tempLeft=1;
            end
            if(n3sgramFrame(j)==min(n3sgramFrame(tempLeft:j+10)))
                %Ҳ������Сֵ?
                peakLeft=j;
                peakLeftValue=n3sgramFrame(j);
                break;
            end
        end
        if(peakLeft==peak)
            peakLeft=1;
        end
        disp(strcat('�󲨹�at time : ',num2str(peakLeft)));
        for j=peak:length(n3sgramFrame)
            tempLeft=j;
            if tempLeft-peak>10
                tempLeft=tempLeft-10;
            else
                tempLeft=peak;
            end
            if(n3sgramFrame(j)==min(n3sgramFrame(tempLeft:j+10)))
                %Ҳ������Сֵ?
                peakRight=j;
                peakRightValue=n3sgramFrame(j);
                break;
            end
        end
        disp(strcat('�Ҳ���at time : ',num2str(peakRight)));
        figure;plot(n3sgramFrame);
return;