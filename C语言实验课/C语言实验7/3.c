#include<stdio.h>
void paixu(int *a)
{
	int i,j;
    for(j=0;j<sizeof(a)/sizeof(a[0]);j++)
	for(i=0;i<10-(sizeof(a)/sizeof(a[0]));i++)
		if(a[i]>a[i+1])
		{
			int q;
			q=a[i+1];
			a[i+1]=a[i];
			a[i]=q;
		}
}
int main(int argv ,const char *argv())
{
	int i;
	int shu[10];
	for(i=0;i<10;i++)
	scanf("%d",&shu[i]);
	paixu(&shu);
	for(i=0;i<10;i++)
	printf("%d",shu[i]); 
}
