#include <stdio.h>
#define N 10
int main()
{
	int i,j;int a[N][N];
	void yanghui(int a[][N]);      //申明yanghui函数
	yanghui(a);      //调用yanghui函数
	for (i=0;i<N;i++)
	{
	for (j=0;j<=i;j++)
	printf("%-4d",a[i][j]);
	printf("\n");
	}	
	return 0;
}
void yanghui(int a[][N])
{
	int i,j;
 	for (i=0;i<N;i++)
 	{
	 a[i][0]=1;
	 a[i][i]=1;
	}        
 	for (i=2;i<N;i++)
		for (j=1;j<=i-1;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];       
}
