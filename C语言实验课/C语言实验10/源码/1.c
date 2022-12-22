#include <stdio.h>
int main()
{
    FILE *fp;
    char ch,fname[10];
    printf("请输入文件名:");
    gets(fname);
    if((fp=fopen(fname,"a"))==NULL)
    {
    printf("不能打开文件！\n");exit(0);
    }
    while((ch=getchar())!='!')
    fputc(ch,fp);
    fclose(fp);
    return 0;
}
