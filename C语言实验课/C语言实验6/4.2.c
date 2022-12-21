#include<stdio.h>
int prime(int i)
{
    
    for(int x=2;x<i;x++)
    {
        if(i%x==0) return 0;
    }
    return 1;
}
int main()
{
    for(int i=100;i<=200;i++)
    {
        if((prime(i))==1) printf("%d ",i);
    }
}