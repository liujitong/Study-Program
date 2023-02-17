#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	if(ch>='0'&&ch<='9')
	printf("%d",ch-'0');
	else
	printf("error");

return 0;
}
