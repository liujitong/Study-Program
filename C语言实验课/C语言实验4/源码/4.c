#include<stdio.h>
int main()
{
    float s=0;
    int x=1,y=2;
    int z,i;
    for(i=1;i<=20;i++)
    {
        s=s+1.0*x/y;
        z=x;
        x=y;
        y=z+y;

    }
    printf("%f",s);
    return 0;
}//2022212080 刘纪彤