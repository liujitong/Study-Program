#include<stdio.h>
int main()
{
    for(int i=2;i<=1000;i++)
    {
        int sum=0;
        for(int z=1;z<i;z++) if(i%z==0) sum+=z;
        if(sum==i) printf("%d,",i);
        
    }
    return 0;
}
