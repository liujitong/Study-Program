#include <stdio.h>
#include <string.h>
#define NUM 4
struct student
{
    int rank;
    char name[20];
    float score;
};
struct student stu[]={3,"Tom",89.5,4,"Mary",68,1,"Hebe",96.5,2,"Jim",92};
int main()
{
    char str[10];int i;
    do
    {
    printf("����������:");
     scanf("%s",str);
    for(i=0;i<NUM;i++)
      if(strcmp(stu[i].name, str) == 0)       //����ҵ�
      {
        printf("name:%s\n",stu[i].name);      //������� 
        printf("rank:%d\n",stu[i].rank);      //�������
        printf("score:%5.1f\n",stu[i].score);     //����ɼ�
      }
    if (i>=NUM) printf("Not find\n");
    }while(strcmp(str,"0")!=0);
return 0;
}
