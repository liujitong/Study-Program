t=[1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8].';
y=[33.4,79.5,122.65,159.05,189.15,214.15,238.65,252.2,267.55,280.50,296.65,301.65,310.40,318.15,325.15].';
A=[1,g2(t(1)),g3(t(1));1,g2(t(2)),g3(t(2));1,g2(t(3)),g3(t(3));1,g2(t(4)),g3(t(4));1,g2(t(5)),g3(t(5));1,g2(t(6)),g3(t(6));1,g2(t(7)),g3(t(7));1,g2(t(8)),g3(t(8));1,g2(t(9)),g3(t(9));1,g2(t(10)),g3(t(10));1,g2(t(11)),g3(t(11));1,g2(t(12)),g3(t(12));1,g2(t(13)),g3(t(13));1,g2(t(14)),g3(t(14));1,g2(t(15)),g3(t(15))];
G=A.'*A;
b=A.'*y;
L=chol(G);%cholesky分解
x=L\(L.'\b);
disp(x);%求出a,b,c的值
ss=zeros(15,1);
for i=1:15
    ss(i)=s(t(i));
end
diff=ss-y;
c=sum(diff.^2);%求平方和
sig=sqrt(c/15);%均方误差
disp(sig);