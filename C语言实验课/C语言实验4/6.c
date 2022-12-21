#include<stdio.h>
int main()
{
    char c;
    int letters=0,space=0,number=0,others=0;
    while((c=getchar())!='\n')
    {
        if(c<='Z'&&c>='A'||c<='z'&&c>='a') letters++;
        else if (c==' ') space++;
        else if (c>='0'&&c<='9') number++;
        else others++;
    }
    printf("%d %d %d %d",letters,space,number,others);
    return 0;
}