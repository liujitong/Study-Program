#include<stdio.h>

int main()
{
    int x;//用户输入数
    int n;//位数
    int s=0;
    scanf("%d",&x);
    int t=x;//确定好位数
    for(n=0;x>s;n++)//计算位数
    {
        s=s*10+1;
    }
    for(;;)
    { 
        printf("%d",s/x);//输出商
        s=s%x;//保存余数
        if(s==0) break;//余数为零跳出循环
        s=s*10+1;//除式
        n++;
    }
 printf(" %d",n);
 return 0;
}