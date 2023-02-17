#include <stdio.h>
#include <string.h>

// 求字符串长度的函数，函数中使用指针变量作为形参
int get_string_length(char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
int main()
{
    char str[100];
    int length;
    scanf("%s",str);
    length=get_string_length(str);
    printf("%d",length);
    return 0;
}