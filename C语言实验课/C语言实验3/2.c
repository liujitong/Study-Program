#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)//�жϴ�ʱ�Ƿ�����a>b 
	{
	    if(b>c)//b>c 
	    {
		printf("%d %d %d",c,b,a);//��Ȼ�ó�a>b>c 
		}
		else if(a>c)//b<c 
		{
			printf("%d %d %d",b,c,a);//a>c>b
		}
		else{
			printf("%d %d %d",b,a,c);//c>a>b
		}		
	}
	else if(a>c)//��ʱ������Ϊa,b������ͬ���֤ 
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
 } //2022212080����ͮ 
