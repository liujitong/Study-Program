function yy=lagr(x,y,xx)

% yy=nalagr(x,y,xx)�����������ղ�ֵ������x�ǲ�ֵ�ڵ㣬y�Ƕ�Ӧ��������%xx�ǲ�ֵ�㣬Ҳ����������

disp('�������ղ�ֵ');

x=-5:1:5

y=1./(1+16*x.^2)

plot(x,y,'r');

hold on;

xx=5.*cos((2.*[0:1:20]+1)*pi./42)

m=length(x);

n=length(y);

if m~=n

    error('����x������y�ĳ��ȱ���һ��')

end

s=0;

for i=1:n

    t=ones(1,length(xx));

    for j=1:n

        if j~=i

            t=t.*((xx-x(j))/(x(i)-x(j)))

        end

    end

    s=s+t*y(i);

end

yy=s;

yy

plot(xx,yy,'k');
