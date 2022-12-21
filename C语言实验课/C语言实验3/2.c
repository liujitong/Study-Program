#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)//判断此时是否满足a>b 
	{
	    if(b>c)//b>c 
	    {
		printf("%d %d %d",c,b,a);//显然得出a>b>c 
		}
		else if(a>c)//b<c 
		{
			printf("%d %d %d",b,c,a);//a>c>b
		}
		else{
			printf("%d %d %d",b,a,c);//c>a>b
		}		
	}
	else if(a>c)//此时条件下为a,b，以下同理可证 
	{
		printf("%d %d %d",c,a,b);
	}
	else if(b>c)
	{
		printf("%d %d %d",a,c,b);
		
	}
	else{
		printf("%d %d %d",a,b,c);
}
	return 0;
 } //2022212080刘纪彤 
