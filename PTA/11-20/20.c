#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num1,num2;//设置两个标志数
    char sys;//定义运算符
    scanf("%d",&num1);//读取第一个数
    while((sys=getchar())!='=')
    {
       scanf("%d",&num2);
       if(num2==0&&sys=='/'){
        printf("ERROR");
        return 0;
       }
       switch(sys){
        case '+':num1+=num2;break;//加法
        case '-':num1-=num2;break;//减法
        case '*':num1*=num2;break;//乘法
        case '/':num1/=num2;break;//除法
        default:printf("ERROR");return 0;
       }//此switch用来识别sys运算符
    }
    printf("%d",num1);
    system("pause");
    return 0;
}/*模拟简单运算器的工作。假设计算器只能进行加减乘除运算，运算数和结果都是整数，四种运算符的优先级相同，按从左到右的顺序计算。

输入格式:
输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。

输出格式:
在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。

输入样例:
1+2*10-10/2=
输出样例:
10
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/