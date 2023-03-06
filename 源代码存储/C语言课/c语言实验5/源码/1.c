#include<stdio.h>
int main() 
{
    int i,a[10];
    float average;
    for (i=0;i<10;i++)
    {
    scanf("%d",&a[i]);
    average=average+a[i];
    }
    for (i=0;i<10;i++)
    {
    printf("%d ",a[i]);
    if ((i+1)%3==0) printf("\n");
    }
    average=average+a[i];
    printf("average=%f\n",average/10.0);
    return 0;
}
