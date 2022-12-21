#include <stdio.h>
struct n
{
    int x;
    char c;
};
int main()
{
    void func(struct n );
    struct n a={10,'x'};
    func(a);
    printf("%d,%c",a.x,a.c);
    return 0;
}
void func(struct n b )
{
    b.x=20;
    b.c='y';
}
