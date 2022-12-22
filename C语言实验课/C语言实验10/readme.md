# 实验10　文件

一、实验目的

1.掌握文件和文件指针的概念。

2.掌握使用文件操作函数实现对文件进行打开、关闭、读、写等操作。

3.掌握对数据文件进行简单的操作。

4.函数，结构体和文件的综合应用。

三、实验内容
1.以下程序的功能是：由终端键盘输入字符，存放到文件fname中，用“!”结束输入。请填空。

```c
#include <stdio.h>
int main()
{FILE *fp;
 char ch,fname[10];
 printf("请输入文件名:");
 gets(fname);
 if ((fp=________________)==NULL)
 {printf("不能打开文件！\n");exit(0);}
while(______________)!='!')
 fputc(__________________);
fclose(fp);
return 0;
}
```

2.以下程序的功能是：打开第1题所保存的文件，将文件内容输出到屏幕上，并统计文件中数字字符的个数。请填空。

```c
#include <stdio.h>
int main()
{FILE *fp;int count=0;
 char ch,fname[10];
 printf("请输入文件名:");
 gets(fname);
 if ((fp=fopen(________________))==NULL)
 {printf("不能打开文件！\n");exit(0);}
 printf("文件中的内容为：\n");
while(______________)
{ch=__________________;
 putchar(ch);
 if (ch>='0' && ch<='9') 
 count++;}
printf("\n数字字符的个数为：%d\n",count);
fclose(fp);
return 0;
}
```

3.以下程序的功能是：输入4名学生的姓名、学号、年龄并存入文件stu_list.dat中。请填空。

```c
#include <stdio.h>
#define SIZE 4
struct student_type
{char name[10];
 int num;
 int age;
}stud[SIZE];
void save()
{FILE *fp;
 int i;
 if ((fp=fopen("stu_list.dat","wb"))==NULL)
 {printf("不能打开文件！\n");
 return;}
 for(i=0;i<SIZE;i++)
 if(fwrite( ____________________________)!=1)
   printf("写文件出错！\n");
fclose(fp);
}

int main()
{int i;
 for (i=0;i<SIZE;i++)
 scanf("%s,%d,%d",__________________________________);
 save();
return 0;
}
```

4.在一个文件中保存许多姓名，每个姓名占一行。 编写程序，从键盘输入该文件的文件名和一个姓名，判断该姓名在文件中是否存在。

5.有5个学生的学号、姓名、三门课程的成绩，从键盘输入以上数据，计算出平均成绩，将学号、姓名、三门课程成绩、平均成绩都存放在磁盘文件stu_score。

设5名学生的学号、姓名、三门课程成绩如下：

|学号|姓名|三门课程成绩
|----|----|--
1001  |Cheng   |90,89,80
1002  |Li       |80,80,65
1003  |Zhang   |70,90,80
1004  |Wang     |85,80,88
1005  |Zhao    |70,75,68
