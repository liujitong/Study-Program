function [ result ] = coefficients( img , choose , flag) % flag=0,Ϊ512*512;flag=1��Ϊ8*8
% ���ھ���dct�任���ϵ�����󣬷�0���������������Ͻǣ����½Ƕ��ӽ���0�����Խ���ȥ����ʵ��ѹ����
    
    % 512*512����dctѹ��������ǰ����ʵ��������
    if(flag == 0)
        result = img;
        k = 512 * sqrt(choose);
        for i = 1 : 512
            for j = 1 : 512
                if(i > k || j > k)
                    result(i , j) = 0;
                end
            end
        end         
    end
    if (flag == 1)
        % 8*8��dctѹ���ο�http://www.doc88.com/p-2129986101481.html
        % �����ͨ��һ��ֻ�����Ͻ�Ϊ1�ľ������blkproc������ʵ�֡�ͨ�����������1�ĸ���������ʵ�ֲ�ͬ�̶ȵ�ѹ����
        mask1 = [1 1 1 1 0 0 0 0 % 1/4 DCT
                 1 1 1 1 0 0 0 0
                 1 1 1 1 0 0 0 0
                 1 1 1 1 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0]; 
        mask2 = [1 1 0 0 0 0 0 0 % 1/16 DCT
                 1 1 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0]; 
        mask3 = [1 0 0 0 0 0 0 0 % 1/64 DCT
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0
                 0 0 0 0 0 0 0 0];
        mask = mask1;
        if(choose == 1/4)
            mask = mask1;
        elseif(choose == 1/16)
            mask = mask2;
        else
            mask = mask3;
        end
        T = dctmtx(8);
        B = blkproc(img , [8 8] , 'P1.*x' ,mask); % ����1/4 �� 1/16 �� 1/64��DCTϵ��
        result = blkproc(B , [8 8] , 'P1*x*P2' , T' , T); % ��任���ع�
    end
end

