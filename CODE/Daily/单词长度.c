#include<stdio.h>
int main()
{
    char c=1;//定义字符并初始化
    int count=0;
    int flag=0;
    int flag2=0;//保证未输入情况之下没有输出
    while((c=getchar())!='.')//不等于 '.'就循环
    {
        if(c!=' ') count++;
        if(c==' '&&count>0)
        {
            if(flag>0) printf(" ");//如果不为第一个根据格式应该输出一个 
            printf("%d",count);
            count=0;
            flag++;
            flag2++;
        }
    } 
    if(count>0&&flag2>0)
    {
        printf(" %d",count);
    }
    else if(count>0&&flag2==0)//count=0,flag2=0的情况下应该没有输出
    {
        printf("%d",count);
    }
       return 0;
}