#include<stdio.h>
int Double(int a[10])
{
    int sum=0;
    for(int i=0;i<10;i++)
    {
        if(a[i]%2==0) sum++;
    }
    return sum;
}
int main()
{
    int a[10];
    for(int i=0;i<10;i++) scanf("%d",&a[i]);
    int sum=0;
    sum=Double(a);
    printf("%d",sum);
    return 0;
}
