#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 5 // 定义最大学生人数
#define PASS_MARK 60 // 定义及格分数
#define EXCELLENT_MARK 90 // 定义优秀分数

// 全班各门课程总分
float total_marks[5];

// 全班各门课程平均分
float average_marks[5];

// 全班各分数段人数
int scores[5];

//总计输入
int sum_input;

// 学生信息结构体
typedef struct {
  char  id[10]; // 学号
  char name[50]; // 姓名
  float marks[5]; // 成绩
  float average; // 平均分
  int rank; // 名次
} Student;

// 全班学生信息
Student students[MAX_STUDENTS];

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
	printf("*       0.退出\n");//退出系统
	printf("********************************\n");
	printf("您的选择是： ");
}
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
void Input_Student()
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
  Save_origin();
}
void Grade_output()
{
  calculate_average();
  sort_students();
  Save_average();
  system("cls");
  printf("*****成绩统计*****\n");
  OUTPUT_GRADES();
}
void Grade_paragraph()
{
  calculate_scores();
  printf("分数段\t科目一\tC科目二\t科目三\t科目四\t科目五\n");
  printf("<60\t%d\t%d\t%d\t%d\t%d\n", scores[0], scores[0], scores[0], scores[0], scores[0]);
  printf("60-69\t%d\t%d\t%d\t%d\t%d\n", scores[1], scores[1], scores[1], scores[1], scores[1]);
  printf("70-79\t%d\t%d\t%d\t%d\t%d\n", scores[2], scores[2], scores[2], scores[2], scores[2]);
  printf("80-89\t%d\t%d\t%d\t%d\t%d\n", scores[3], scores[3], scores[3], scores[3], scores[3]);
  printf(">=90\t%d\t%d\t%d\t%d\t%d\n", scores[4], scores[4], scores[4], scores[4], scores[4]);
}
void print_failed_students() // 打印不及格学生信息
{
  printf("学号\t不及格课程\t成绩\n");
  for (int i = 0; i <= sum_input; i++) {
  for (int j = 0; j < 5; j++) {
  if (students[i].marks[j] < PASS_MARK) {
  printf("%s\t%d\t%.1f\n", students[i].id, j + 1, students[i].marks[j]);
  }
  }
  }
}
void print_excellent_students() // 打印优等生信息
{
  printf("学号\t姓名\n");
  for (int i = 0; i < MAX_STUDENTS; i++) {
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
//排序
void sort_students() 
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

void OUTPUT_GRADES()
{
  printf("学号\t姓名\t科目一\t科目二\t科目三\t科目四\t科目五\t平均分数\t排名\t\n");
  for(int i=0;i<=sum_input;i++)
  printf("%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%d\t\n",students[i].id,students[i].name,students[i].marks[0],students[i].marks[1],students[i].marks[2],students[i].marks[3],students[i].marks[4],students[i].average,students[i].rank);
  system("Pause");
}
// 计算全班各分数段人数
void calculate_scores() 
{
for (int i = 0; i <= sum_input; i++) {
for (int j = 0; j < 5; j++) {
if (students[i].marks[j] < 60) {
scores[0]++;
} else if (students[i].marks[j] < 70) {
scores[1]++;
} else if (students[i].marks[j] < 80) {
scores[2]++;
} else if (students[i].marks[j] < 90) {
scores[3]++;
} else {
scores[4]++;
}
}
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
      case 0: return 0;break;
      case 1: Input_Student();break;
      case 2: Grade_output();break;
      case 3: Grade_paragraph();break;
      case 4: print_failed_students();break;
      case 5: print_excellent_students();break;
      default :continue;break;
    }
    }
}