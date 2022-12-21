# 实验9　结构体

一、实验目的

1.掌握结构体类型变量的定义和使用。

2.掌握结构体类型数组的概念和应用。

三、实验内容
1.写出下面程序的预期结果。上机输入并运行下面程序，验证你的结果并分析。

```c
#include <stdio.h>
struct n
{int x;
 char c;
};
int main()
{void func(struct n );
 struct n a={10,'x'};
 func(a);
 printf("%d,%c",a.x,a.c);
return 0;
}
void func(struct n b )
{b.x=20;
 b.c='y';
}
```

2.以下程序用来按学生姓名查询其排名和平均成绩。查询可连续进行，直到输入0时结束。请填空。

```c
#include <stdio.h>
#include <string.h>
#define NUM 4
struct student
{int rank;
 char name[20];
 float score;
};
__________________ stu[]={3,"Tom",89.5,4,"Mary",68,1,"Hebe",96.5,2,"Jim",92};
int main()
{char str[10];int i;
 do
 {printf("请输入姓名:");
  scanf("%s",str);
  for(i=0;i<NUM;i++)
 if(________________________)                  //如果找到
{
printf("name:%s\n",_________________);      //输出姓名 
printf("rank:%d\n",_________________);      //输出名次
printf("score:%5.1f\n",______________);     //输出成绩
}
if (i>=NUM) printf("Not find\n");
 }while(strcmp(str,"0")!=0);
return 0;
}
```

3.函数findbook的功能是：在有M个元素的结构体数组中查找名为name的书。若找到，函数返回数组下标，否则，函数返回一1。
要求：在main函数中输入book数组的信息和要查找的书名，如果找到，则输出该书的相关信息（id,name,price）；如果没有找到，则输出“no find”，请完成main函数的编写。

```c
#include <stdio.h>
#include <string.h>
#define M 5
struct data
{int id;
 char name[20];
 float price;
}book[M];
int findbook(struct data s[],char name[] )
{int i;
 for (i=0;i<M;i++)
   if (strcmp(s[i].name,name)==0) return i;
 return -1;
}
int main()
{
……
}
```
