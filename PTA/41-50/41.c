#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int sum=0,factorial=1;
   for (int i=1; i<=x; i++){
    factorial *= i;
    sum += factorial;
  }
    printf("%d",sum);
}/*对于给定的正整数N，需要你计算 S=1!+2!+3!+...+N!。

输入格式：
输入在一行中给出一个不超过10的正整数N。

输出格式：
在一行中输出S的值。

输入样例：
3
输出样例：
9
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/