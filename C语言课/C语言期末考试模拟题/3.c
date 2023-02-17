#include<stdio.h>
int main()
{
    int a[3][4];
    for(int i=0;i<3;i++)
    {
        for(int z=0;z<4;z++)
        {
            scanf("%d",&a[i][z]);
        }
    }
    int max=a[0][0];
    int h=0,l=0;
    for(int i=0;i<3;i++)
    {
        for(int z=0;z<4;z++)
        {
            if(a[i][z]>max)
            {
                max=a[i][z];
                h=i;
                l=z;
            }
        }
    }
    printf("%d \n第%d行,第%d列",max,h+1,l+1);
}