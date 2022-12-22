#include<stdio.h>
#define MAX_STUDENT 5//最大学生数5
#define MAX_LENGTH 10//最大名字字符数
struct student
{
    int number;
    char name[MAX_LENGTH];
    int score1;
    int score2;
    int score3;
    double average;//平均成绩
}stu[MAX_STUDENT];
int main()
{
    //声明文件指针变量
    FILE *fp;
    // 打开文件，如果文件无法打开，输出错误信息并退出程序
    fp = fopen("stu_score", "w");
    if (fp == NULL) 
    {
        printf("无法打开文件！\n");
        return 1;
    }
    //循环输入每位学生的学号，姓名，三门科目的成绩
    for(int i=0;i<MAX_STUDENT;i++)
    {
        printf("请输入第 %d 个学生的学号：", i + 1);
        scanf("%d", &stu[i].number);
        printf("请输入第 %d 个学生的姓名：", i + 1);
        scanf("%s", stu[i].name);
        printf("请输入第 %d 个学生的三门课程成绩：", i + 1);
        scanf("%d,%d,%d", &stu[i].score1, &stu[i].score2, &stu[i].score3);
    }
    //循环计算每位学生的学习成绩平均值
    for(int i=0;i<MAX_STUDENT;i++)
    {
        stu[i].average=(stu[i].score1 + stu[i].score2 + stu[i].score3) / 3.0;
    }
    //循环写入文件
    for(int i=0;i<MAX_STUDENT;i++)
    {
        fprintf(fp, "学号：%d\n姓名：%s\n三门课程成绩：%d,%d,%d\n平均成绩：%.2lf\n", stu[i].number, stu[i].name, stu[i].score1,stu[i].score2,stu[i].score3,stu[i].average);
    }
    fclose(fp);//关闭文件
    return 0;
}