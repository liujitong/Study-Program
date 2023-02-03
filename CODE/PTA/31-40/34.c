#include<stdio.h>
int main()
{
    double a=2.0,b=1.0;//这里为什么要用double ，当N太大的时候可能int已经不够用了，所以我们需要用double
    double c=0.0;
    long long int N;
    scanf("%lld",&N);
    for(long long int i=1;i<=N;i++)
    {
     double mid;//a和b被定义为double型，那么我必须要把中间值也定义为double型
     c+=1.0*a/b;
     mid=a;
     a=a+b;
     b=mid;
    }
    printf("%.2lf",c);
    return 0;
}
/*本题要求编写程序，计算序列 2/1+3/2+5/3+8/5+... 的前N项之和。注意该序列从第2项起，每一项的分子是前一项分子与分母的和，分母是前一项的分子。

输入格式:
输入在一行中给出一个正整数N。

输出格式:
在一行中输出部分和的值，精确到小数点后两位。题目保证计算结果不超过双精度范围。

输入样例:
20
输出样例:
32.66
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/