#include<stdio.h>
#include<math.h>
int main()
{
    long long int x;
    int wei[65];
    scanf("%lld",&x);
    int y,z,i;
    if(x==0)
    {
        printf("0 ");
        return 0;
    }//需要把零的情况考虑进去
    for(i=1;x!=0;i++)
    {
        wei[i]=x%10;
        x=x/10;
    }
    for(y=i-1;y>0;y--)
    {
        printf("%d ",wei[y]);
    }
return 0;
}/*本题要求编写程序，对输入的一个整数，从高位开始逐位分割并输出它的各位数字。

输入格式：
输入在一行中给出一个长整型范围内的非负整数。

输出格式：
从高位开始逐位输出该整数的各位数字，每个数字后面有一个空格。

输入样例：
123456
输出样例：
1 2 3 4 5 6 
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/