#include<stdio.h>
int main()
{ int x,y;
  char ch1,ch2,ch3;
  scanf("%d,%d",&x,&y);
  getchar();                           //�õ�scanf�������Ļس���
  printf("x=%d,y=%d\n",x,y);
  scanf("%c%c%c",&ch1,&ch2,&ch3);
  printf("ch1=%c,ch2=%c,ch3=%c\n",ch1,ch2,ch3);
  return 0;
}
//202212080����ͮ