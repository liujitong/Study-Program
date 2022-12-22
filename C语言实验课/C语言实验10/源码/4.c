#include <stdio.h>
#include <string.h>

int main()
{
    // 声明文件指针
    FILE *fp;
    // 声明文件名和要查找的姓名的字符串变量
    char fname[100], name[100];
    // 从键盘输入文件名和要查找的姓名
    printf("请输入文件名：");
    scanf("%s", fname);
    printf("请输入姓名：");
    scanf("%s", name);
    //打开文件，并输出判断是否成功打开文件
    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("不能打开文件！\n");
        return 0;
    }//判断能否打开文件

    char line[100];
    while (fgets(line, sizeof(line)-1, fp) != NULL)
    {
        line[strcspn(line, "\n")] = 0;//根据相关实验数据表明我们要把每一行的换行符去掉
        if (strcmp(line,name) == 0)
        {
            printf("找到了！\n");
            fclose(fp);
            return 0;
        }
    }

    printf("没有找到！\n");
    fclose(fp);
    return 0;
}