#include<stdio.h>
int main()
{
    int i;//循环数
    int N;
    int a=1,b=1,sign=1;//数列的初始值和符号
    float sum=0;//和
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
     sum=sum+sign*1.0*a/b;
     a=a+1;
     b=b+2;
     sign=-sign;
    }
    printf("%.3f",sum);
    
}
/*本题要求编写程序，计算交错序列 1-2/3+3/5-4/7+5/9-6/11+... 的前N项之和。

输入格式:
输入在一行中给出一个正整数N。

输出格式:
在一行中输出部分和的值，结果保留三位小数。

输入样例:
5
输出样例:
0.917
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/