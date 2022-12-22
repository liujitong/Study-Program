#include <stdio.h>
int main()
{
    FILE *fp;
    int count=0;
    char ch,fname[10];
    printf("请输入文件名:");
    gets(fname);
    if ((fp=fopen(fname,"rb"))==NULL)
    {
    printf("不能打开文件！\n");
    exit(0);
    }
    printf("文件中的内容为：\n");
    while(feof(fp)==0)
    {
        ch=fgetc(fp);
        if (ch>='0' && ch<='9') count++;
    }
    printf("\n数字字符的个数为：%d\n",count);
    fclose(fp);
    return 0;
}