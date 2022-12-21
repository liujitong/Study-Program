#include<stdio.h>
int main()
{
    float s=0;
    int x;
    int sign=1;
    for(x=1;x<=100;x++)
    {
        s=s+1.0/x*sign;
        sign=(-1)*sign;
    }
    printf("%f",s);
    return 0;
}//2022212080 刘纪彤