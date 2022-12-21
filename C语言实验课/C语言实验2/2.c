#include<stdio.h>
int main()
{
    char letter;//设置小写字母变量
    char Letter;//设置大写字母变量
    letter=getchar();
    Letter = letter-32;//根据ANSI表找到对应的字符
    printf("%c",Letter);
    return 0;
}
//2022212080刘纪彤

