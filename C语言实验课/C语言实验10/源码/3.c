#include <stdio.h>
#define SIZE 4
struct student_type
{
    char name[10];
    int num;
    int age;
}stud[SIZE];
void save()
{
    FILE *fp;
    int i;
    if ((fp=fopen("stu_list.dat","wb"))==NULL)
 {
    printf("不能打开文件！\n");
    return;}
    for(i=0;i<SIZE;i++)
    if(fwrite(&stud[i],sizeof(struct student_type),1,fp)!=1)
    printf("写文件出错！\n");
    fclose(fp);
}

int main()
{int i;
 for (i=0;i<SIZE;i++)
	 scanf("%s,%d,%d",stud[i].name,&stud[i].num,stud[i].age);
 save();
return 0;
}
