#include<stdio.h>
int main()
{
    int n,m;
    int flag=1;//标志
    int count=0,sum=0;
    int i;
    scanf("%d %d",&n,&m);
    for(;n<=m;n++)
    {
        for(i=2;i<n;i++)
        {
         if(n%i==0)
         {
        break;
         } 
        }  
        if(i>=n&&n!=1)
        {
            count++;
            sum+=n;
        }
    }
    
    printf("%d %d",count,sum);
    }
    /*本题要求统计给定整数M和N区间内素数的个数并对它们求和。

输入格式:
输入在一行中给出两个正整数M和N（1≤M≤N≤500）。

输出格式:
在一行中顺序输出M和N区间内素数的个数以及它们的和，数字间以空格分隔。

输入样例:
10 31
输出样例:
7 143
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/