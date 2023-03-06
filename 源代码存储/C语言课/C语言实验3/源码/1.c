#include<stdio.h>
#include<math.h>
int main()
{
	float x,y;
	scanf("%f",&x);
	if(x<0)
	{
		y=fabs(x);
	}
	else if(x<100&&x>=0)
	{
		y=2*x+1;
	}
	else if(x>=100)
	{
		y=sqrt(3*x-10);
	}
	printf("%.2f",y);
	return 0;

 }
