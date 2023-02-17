#include<stdio.h>
int main()
{
    int x;
    float y;
    scanf("%d",&x);
    if(x<0) y=-x;
    else if (x>=0&&x<100) y=4.5*x-10;
    else if (x>=100) y=5.2*x-12;
    printf("%f",y);
    return 0;
}