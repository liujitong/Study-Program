#include<stdio.h>
int prime(int i)
{
    
    for(int x=2;x<i;x++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
    int q;
    scanf("%d",&q);
    printf("%d",prime(q));
}
