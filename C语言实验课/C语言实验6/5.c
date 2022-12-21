#include<stdio.h>
int Fibonacc(int n)
{
    if(n==1|n==2) return 1;
    if(n>2) return Fibonacc(n-1)+Fibonacc(n-2);
}
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d %d",x,Fibonacc(x));
}