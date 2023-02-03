#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d",&x);
	if(x>0) y=1;
	if(x==0) y=0;
	if(x<0) y=-1;
	printf("sign(%d) = %d",x,y);
	return 0; 
}
/*对于任一整数n，符号函数sign(n)的定义如下：
x<0 sign=-1
x=0 sign=0
sign>0 sign=1


请编写程序计算该函数对任一输入整数的值。

输入格式:
输入在一行中给出整数n。

输出格式:
在一行中按照格式“sign(n) = 函数值”输出该整数n对应的函数值。

输入样例1:
10
输出样例1:
sign(10) = 1
输入样例2:
0
输出样例2:
sign(0) = 0
输入样例3:
-98
输出样例3:
sign(-98) = -1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/