#include <stdio.h>
int main()
{
    int x=2,y=5;
    int *l;
    void swap(int,int);
    printf("���ú���ǰx=%d,y=%d\n",x,y);
    swap(x,y);
    printf("���ú�����x=%d,y=%d\n",x,y);
    return 0;
}

void swap(int a,int b)
{
    int t;
    t=a;
    a=b;
    b=t;
    printf("������a,bֵ������a=%d,b=%d\n",a,b);
}
