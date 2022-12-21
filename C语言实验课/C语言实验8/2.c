#include <stdio.h>
int main()
{
    void swap (int *pt1,int *pt2);
    int a,b,c;
    int *p1,*p2,*p3;
    printf("input:a,b,c:");
    scanf("%d,%d,%d",&a,&b,&c);
    p1=&a;
    p2=&b;
    p3=&c;
    if (a>b) swap(p1,p2);
    if (a>c) swap(p1,p3);
    if (b>c) swap(p2,p3);
    printf("out:%d,%d,%d\n",a,b,c);
    return 0;
}
void swap(int *pt1,int *pt2)
{
    int *p;
    p=*pt2;
    *pt2=*pt1;
    *pt1=p;
    
}
 