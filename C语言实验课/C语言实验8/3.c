#include <stdio.h>
int main()
{
    void move(int *pointer);
    int a[3][3],*p,i,j;
    printf("Please input\n");
    for (i=0;i<3;i++)
       for (j=0;j<3;j++)
	//scanf("%d",&a[i][j]);//下标法
    scanf("%d",*(a+i)+j);//指针变量法
    //p=&a[0][0];
    move(a);
    printf("output:\n");
    for (i=0;i<3;i++)
    {
    for (j=0;j<3;j++)
	    //printf("%d ",a[i][j]);//下标法
        printf("%d ",*(*(a+i)+j));//指针变量法
        printf("\n"); 
    }
    return 0;
}
void move(int pointer[])
{
    int i,j,t;
    for (i=0;i<3;i++)
        for (j=i;j<3;j++)
        {
            t=pointer[3*i+j];
            pointer[3*i+j]=pointer[3*j+i];
            pointer[3*j+i]=t;
        }
}
