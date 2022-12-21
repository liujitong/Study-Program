#include<stdio.h>
int main()
{ int i;
  scanf("%d",&i);
  switch(i)
  {case 1:
   case 2:printf("i=");
   case 3:printf("%d\n",i);break;
   default:printf("ok!\n");
  }
   return 0;
}

