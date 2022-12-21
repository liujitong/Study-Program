#include <stdio.h>
#include <string.h>
#define M 5
struct data
{
    int id;
    char name[20];
    float price;
}book[M];
int findbook(struct data s[],char name[] )
{
    int i;
    for (i=0;i<M;i++)
    if (strcmp(s[i].name,name)==0) return i;
    return -1;
}
int main()
{
    // 输入书籍信息
    for (int i = 0; i < M; i++) {
        printf("输入第 %d 本书的 id、名称和价格（用空格隔开）：", i + 1);
        scanf("%d %s %f", &book[i].id, book[i].name, &book[i].price);
    }
    // 输入要查找的书的名称
    char search_name[20];
    printf("输入要查找的书的名称：");
    scanf("%s", search_name);
    // 调用 findbook 函数来查找书
    int result = findbook(book, search_name);
    // 打印结果
    if (result == -1) {
        printf("没有名为 %s 的书。\n", search_name);
    } else {
        printf("找到了 id 为 %d，名称为 %s，价格为 %.2f 的书。\n", book[result].id, book[result].name, book[result].price);
    }
    return 0;
}