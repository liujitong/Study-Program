#include <stdio.h>
float sum(float a,float b);
int main()
{
    float x,y;
    scanf("%f %f",&x,&y);//没有输入
    printf("%f\n",sum(x,y));//第一处错误
    return 0;
}
float sum (float a,float b)
{
    float c;
    c=a+b;//传入的时候是a和b显然最后用的时候也应该是a和b
    return c;//返回值为c
}
