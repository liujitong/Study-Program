#include<stdio.h>
struct student
{
    int id;
    char name[10];
    int ping;
    int qimo;
    float to;
    /* data */
}stu[5];

int main()
{
    for(int i=0;i<5;i++)
    {
        scanf("%d %s %d %d",&stu[i].id,stu[i].name,&stu[i].ping,&stu[i].qimo);
        stu[i].to=0.3*stu[i].ping+0.7*stu[i].qimo;
    }
    for(int i=0;i<5;i++)
    {
        printf("%d %s %d %d %.2f\n",stu[i].id,stu[i].name,stu[i].ping,stu[i].qimo,stu[i].to);
    }
    return 0;
}