#include<stdio.h>
void yswap(char *a,char *b)
{
    int sum=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        {
            b[sum]=a[i]; 
            sum++;
        }
    }
}
int main()
{
    char a[1000],b[1000];//a表示原字符串，b表示元音字符串
    gets(a);
    yswap(a,b);
    for(int i=0;b[i]!='\0';i++)
    {
        printf("%c",b[i]);
    }
}
