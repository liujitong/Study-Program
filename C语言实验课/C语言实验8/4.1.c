#include <stdio.h>
#include <string.h>
int get_string_length(char str[])
{
    int length = 0;
    length = strlen(str);
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