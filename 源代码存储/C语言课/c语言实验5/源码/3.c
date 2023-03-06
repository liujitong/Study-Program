#include <stdio.h>
int main()
{
    int i,j,m,n,x[3][4]={10,20,30,40,1,2,3,4,33,83,73,13};
    m=n=0;
    for(i=0;i<3;i++)//使i循环
    for(j=0;j<4;j++)//使j循环
	if(x[m][n]<x[i][j]) //比较大小，如果小
	{
        m=i;//交换1
        n=j;//交换2
    }
    printf("x[m][n]=%d,m=%d,n=%d",x[m][n],m,n);//交换
    return 0;
}
