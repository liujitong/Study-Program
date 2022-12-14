#include<stdio.h>
int main()
{
    int N0;
    int i;//记录次数
    int sum=0;//各位数字相加求和
    int x;
    scanf("%d",&N0);//输入NO
    for(i=1;;i++)
    {
        x=N0;
        sum=0;
        for(;N0!=0;)
        {
            sum=sum+(N0%10);
            N0/=10;
        }//计算各位数字求和
        printf("%d:%d\n",i,sum*3+1);
        if((sum*3+1)==x) break;
        N0=sum*3+1;   
    }
}
/*对任意一个自然数N 
0
​
 ，先将其各位数字相加求和，再将其和乘以3后加上1，变成一个新自然数N 
1
​
 ；然后对N 
1
​
 重复这种操作，可以产生新自然数N 
2
​
 ；……多次重复这种操作，运算结果最终会得到一个固定不变的数N 
k
​
 ，就像掉入一个数字“陷阱”。

本题要求对输入的自然数，给出其掉入“陷阱”的过程。

输入格式:
在一行内给出一个自然数N 
0
​
 （N 
0
​
 <30000）。

输出格式:
对于输入的N 
0
​
 ，逐行输出其掉入陷阱的步骤。第i行描述N掉入陷阱的第i步，格式为： i:N 
i
​
  （i≥1）。当某一步得到的自然数结果N 
k
​
 (k≥1)与上一步N 
k−1
​
 相同时，停止输出。

输入样例:
5
输出样例:
1:16
2:22
3:13
4:13
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/