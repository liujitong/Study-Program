#include <stdio.h>
int main()
{
    int x=2,y=5;
    int *l;
    void swap(int,int);
    printf("调用函数前x=%d,y=%d\n",x,y);
    swap(x,y);
    printf("调用函数后x=%d,y=%d\n",x,y);
    return 0;
}

void swap(int a,int b)
{
    int t;
    t=a;
    a=b;
    b=t;
    printf("函数中a,b值交换后a=%d,b=%d\n",a,b);
}
