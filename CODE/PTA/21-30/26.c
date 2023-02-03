#include<stdio.h>
int gys(int a,int b)
{
   int z;
   if(a<b)
   {
    z=a;
    a=b;
    b=z;
   }//这一步我要确保x>y
   while(b!=0)
   {
    z=a%b;
    a=b;
    b=z;
   }//这一步利用辗转相除法求公约数
   return (a);
}//gys函数主要用于求解最大公约数
int main()
{
    int x,y,gys1,gbs;
    scanf("%d %d",&x,&y);
    gys1=gys(x,y);//调用定义的gys函数
    gbs=x*y/gys1;//求解公倍数
     printf("%d %d",gys1,gbs);
     return 0;
}
/*本题要求两个给定正整数的最大公约数和最小公倍数。

输入格式:
输入在一行中给出两个正整数M和N（≤1000）。

输出格式:
在一行中顺序输出M和N的最大公约数和最小公倍数，两数字间以1空格分隔。

输入样例:
511 292
输出样例:
73 2044
鸣谢安阳师范学院段晓云老师和软件工程五班李富龙同学补充测试数据！

代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/