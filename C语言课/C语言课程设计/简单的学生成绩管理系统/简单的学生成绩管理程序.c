#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//宏定义
#define MAX_STUDENTS 50 // 定义最大学生人数
#define PASS_MARK 60 // 定义及格分数
//全局变量定义
float total_marks[5];// 全班各门课程总分
float average_marks[5];// 全班各门课程平均分
int scores_by_subjects[5][5] = {{0}};// 全班各分数段人数
int sum_input=-1;//总计输入学生人数
// 学生信息结构体
typedef struct {
  char  id[10]; // 学号
  char name[50]; // 姓名
  float marks[5]; // 成绩
  float average; // 平均分
  int rank; // 名次
} Student;
Student students[MAX_STUDENTS];// 全班学生信息

//菜单区
void WELCOME_screen()
{
    printf("**********************************\n*****欢迎使用学生成绩管理系统*****\n*****作者：刘纪彤*****************\n**********************************\n");
    system("Pause");
}
void menu()
{
  system("cls");
  printf("*************菜单***************\n");
	printf("*       1.学生条目输入\n");
	printf("*       2.成绩统计\n");
	printf("*       3.分数段统计\n");
	printf("*       4.不及格学生筛选\n");
	printf("*       5.优秀学生统计\n");
	printf("*       0.退出并保存文件\n");//退出系统
	printf("********************************\n");
	printf("您的选择是： ");
}

//流程区
void Input_Student()//输入学生信息
{

  system("cls");
  printf("输入0退出\n");
  int i;
  for(i=0;i<MAX_STUDENTS;i++)
  {
  system("cls");
  printf("请输入学号:");
  scanf("%s",students[i].id);
  printf("请输入姓名:");
  scanf("%s",students[i].name);
  printf("请输入科目一成绩:");
  scanf("%f",&students[i].marks[0]);
  printf("请输入科目二成绩:");
  scanf("%f",&students[i].marks[1]);
  printf("请输入科目三成绩:");
  scanf("%f",&students[i].marks[2]);
  printf("请输入科目四成绩:");
  scanf("%f",&students[i].marks[3]);
  printf("请输入科目五成绩:");
  scanf("%f",&students[i].marks[4]);
  printf("继续吗？输入0退出，输入1和其他数字继续。\n");
  int choice;
  scanf("%d",&choice);
  if(choice==0) break;
  else continue;;
  }
  sum_input=i;
}
void Grade_output()//输出成绩统计
{
  calculate_average();
  sort_students();
  system("cls");
  printf("*****成绩统计*****\n");
  OUTPUT_GRADES();
}
void Grade_paragraph()//输出成绩段统计
{
  system("cls");
  // 统计全班各科目的各分数段人数
  for (int i = 0; i < 5; i++) 
  {
    calculate_scores(i);
  }
// 打印表格
  print_scores_table();
  system("Pause");
}
void print_failed_students() // 打印不及格学生信息
{
  system("cls");
  printf("学号\t不及格课程\t成绩\n");
  for (int i = 0; i <= sum_input; i++) {
  for (int j = 0; j < 5; j++) {
  if (students[i].marks[j] < PASS_MARK) {
  printf("%s\t科目%d\t%.1f\n", students[i].id, j + 1, students[i].marks[j]);
  }
  }
  }
  system("Pause");
}
void print_excellent_students() // 打印优等生信息
{
  system("cls");
  printf("学号\t姓名\n");
  for (int i = 0; i <= sum_input; i++) {
    // 满足条件1
    if (students[i].average >= 80) {
      printf("%s\t%s\n", students[i].id, students[i].name);
      continue;
    }

    // 满足条件2
    int has_mark_over_90 = 0;
    for (int j = 0; j < 5; j++) {
      if (students[i].marks[j] >= 90) {
        has_mark_over_90 = 1;
        break;
      }
    }
    if (has_mark_over_90) {
      printf("%s\t%s\n", students[i].id, students[i].name);
      continue;
    }

    // 满足条件3
    int has_full_mark = 0;
    for (int j = 0; j < 5; j++) {
      if (students[i].marks[j] == 100) {
        has_full_mark = 1;
        break;
      }
    }
    if (has_full_mark) {
      printf("%s\t%s\n", students[i].id, students[i].name);
      continue;
    }
  }
  system("Pause");
}

//运算函数区

// 计算学生的平均分
void calculate_average() 
{
  for (int i = 0; i <= sum_input; i++) {
    float sum = 0;
    for (int j = 0; j < 5; j++) 
    {
      sum += students[i].marks[j];
    }
    students[i].average = sum / 5;
  }
}

void sort_students()//排序 
{
  // 按平均分排序
  for (int i = 0; i <= sum_input; i++) 
  {
    for (int j = i + 1; j <= sum_input; j++) 
    {
      if (students[i].average < students[j].average) 
      {
      Student temp = students[i];
      students[i] = students[j];
      students[j] = temp;
      }
    }
  }

  // 计算名次
  students[0].rank = 1;
  for (int i = 1; i <= sum_input; i++) 
  {
  if (students[i].average == students[i - 1].average) 
  {
  students[i].rank = students[i - 1].rank;
  } 
  else 
  {
  students[i].rank = i + 1;
  }
  }
  }

void OUTPUT_GRADES()
{
  printf("学号\t姓名\t科目一\t科目二\t科目三\t科目四\t科目五\t平均分数\t排名\t\n");
  for(int i=0;i<=sum_input;i++)
  printf("%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%d\t\n",students[i].id,students[i].name,students[i].marks[0],students[i].marks[1],students[i].marks[2],students[i].marks[3],students[i].marks[4],students[i].average,students[i].rank);
  system("Pause");
}

void calculate_scores(int subject)// 计算全班各分数段人数 
{
  for (int i = 0; i <= sum_input; i++) {
    int mark = students[i].marks[subject];
    if (mark < 60) {
      scores_by_subjects[subject][0]++;
    } else if (mark < 70) {
      scores_by_subjects[subject][1]++;
    } else if (mark < 80) {
      scores_by_subjects[subject][2]++;
    } else if (mark < 90) {
      scores_by_subjects[subject][3]++;
    } else {
      scores_by_subjects[subject][4]++;
    }
  }
}

void print_scores_table() // 打印表格
{
  printf("科目\t<60\t60~69\t70~79\t80~89\t90~100\n");
  for (int i = 0; i < 5; i++) {
    printf("%d\t", i+1);
    for (int j = 0; j < 5; j++) {
      printf("%d\t", scores_by_subjects[i][j]);
    }
    printf("\n");
  }
}

//保存文件
void Save_origin()
{
  FILE *fp;
  if ((fp = fopen("data.txt", "w")) == NULL)
  {
    printf("不能打开文件！\n");
  }
  fprintf(fp,"学号\t姓名\t科目一\t\t科目二\t\t科目三\t\t科目四\t\t科目五\t\t\n");
  for(int i=0;i<=sum_input;i++)
  fprintf(fp,"%s\t\t%s\t\t%3.1f\t\t%3.1f\t\t%3.1f\t\t%3.1f\t\t%3.1f\t\t\n",students[i].id,students[i].name,students[i].marks[0],students[i].marks[1],students[i].marks[2],students[i].marks[3],students[i].marks[4]);
  fclose(fp);
}

void Save_average()
{
  FILE *fp;
  if ((fp = fopen("GRADE.txt", "w")) == NULL)
  {
    printf("不能打开文件！\n");
  }
  fprintf(fp,"学号\t姓名\t科目一\t\t科目二\t\t科目三\t\t科目四\t\t科目五\t\t平均分数\t\t排名\t\t\n");
  for(int i=0;i<=sum_input;i++)
  fprintf(fp,"%s\t\t%s\t\t%3.1f\t\t%3.1f\t\t%3.1f\t\t%3.1f\t\t%3.1f\t\t%3.1f\t\t%d\t\t\n",students[i].id,students[i].name,students[i].marks[0],students[i].marks[1],students[i].marks[2],students[i].marks[3],students[i].marks[4],students[i].average,students[i].rank);
  fclose(fp);
}

void Save_paragraph()
{
  FILE *fp;
  if ((fp = fopen("PARA.txt", "w")) == NULL)
  {
    printf("不能打开文件！\n");
  }
 fprintf(fp,"科目\t<60\t60~69\t70~79\t80~89\t90~100\n");
  for (int i = 0; i < 5; i++) {
    fprintf(fp,"%d\t", i+1);
    for (int j = 0; j < 5; j++) {
    fprintf(fp,"%d\t", scores_by_subjects[i][j]);
    }
    fprintf(fp,"\n");
  }
}

//主函数
int main()
{
    WELCOME_screen();
    while(1)
    {
    menu();
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
      case 0: goto Save;break;
      case 1: Input_Student();break;
      case 2: Grade_output();break;
      case 3: Grade_paragraph();break;
      case 4: print_failed_students();break;
      case 5: print_excellent_students();break;
      default :continue;break;
    }
    }
    //保存文件
    Save:
    Save_origin();
    Save_average();
    Save_paragraph();
    return 0;
}