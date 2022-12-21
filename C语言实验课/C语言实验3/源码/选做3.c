#include<stdio.h>
int main()
{
	int x,y;
	int re;
	char op;
	scanf("%d%c%d",&x,&op,&y);
	if(op=='+') re=x+y;
	if(op=='-') re=x-y;
	if(op=='*') re=x*y;
	if(op=='/') re=x/y;
	printf("=%d",re);
	return 0;
 } 
