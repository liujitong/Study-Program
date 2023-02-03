#include<stdio.h>
int main()
{
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    if(x==y) printf("C");
    if(x==z) printf("B");
    if(y==z) printf("A");
    return 0;
}/*三个球A、B、C，大小形状相同且其中有一个球与其他球重量不同。要求找出这个不一样的球。

输入格式：
输入在一行中给出3个正整数，顺序对应球A、B、C的重量。

输出格式：
在一行中输出唯一的那个不一样的球。

输入样例：
1 1 2
输出样例：
C
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/