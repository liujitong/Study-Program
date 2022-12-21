#include <stdio.h>
#define SIZE 12
int main()
{
    int a[SIZE],i,j,t;
    for(i=0;i<SIZE;i++) scanf("%d",&a[i]);
    i=0;
    j=SIZE-1;
    while(i<j)
    {
    t=a[i];
    a[i]=a[j];
    a[j]=t;
    i++;
    j--;
    }
    for (i=0;i<SIZE;i++) printf("%3d",a[i]);
    printf("\n");
    return 0;
}
