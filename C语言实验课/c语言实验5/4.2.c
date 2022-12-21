#include<stdio.h>
void main()
{
int i,j,min,temp,a[11];
printf("enter data;\n");
for(i=1;i<=10;i++)
{
scanf("%d",&a[i]);
}
printf("\n");
printf("yuanshun");
for(i=1;i<=10;i++)
printf("%5d",a[i]);
printf("\n");
for(i=1;i<=9;i++)
{min=i;
for(j=i+1;j<=10;j++)
if(a[min]>a[j])min=j;
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
printf("\nThe sored numbers;\n");
for(i=1;i<=10;i++)
printf("%5d",a[i]);

}

