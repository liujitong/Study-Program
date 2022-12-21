#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float s;
	int sq;
	scanf("%d %d %d",&a,&b,&c);
	s=(a+b+c)/2.0;
	sq=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("%d",sq);
	return 0;
}
//2022212080Áõ¼ÍÍ® 
