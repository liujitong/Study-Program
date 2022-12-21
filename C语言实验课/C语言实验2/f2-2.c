#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
    a=a+b;
	b=a-b;
	a=(a+b)/2;
	b=(a-b);
	printf("a=%d b=%d",a,b);
	return 0; 
 } 
 //2022212080刘纪彤
 //不借助其他变量 
