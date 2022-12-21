#include <stdio.h>
int main()
{
    int a[10]={2,3,5,6,8,10,11,12,14},i,j,m;
    scanf("%d",&m);
    for(i=8;i>=0;i--)
    {
    if(a[i]>m) a[i+1]=a[i];//将比这书大的数存放于后一位
    else if(a[i]<m)
    {
    a[i+1]=m;//当m比数组中的数大时则存入该书的后一位
    break;
    }
    }
    for(i=0;i<10;i++) printf("%d ",a[i]);
    return 0;
}

