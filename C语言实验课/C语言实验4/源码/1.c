#include<stdio.h>
int main()
{ int i,j;
  for (i=1;i<=4;i++)
	 {for (j=1;j<=10-i;j++)	    printf(" ");     //输出*之前的空格
	  for (j=1;j<=2*i-1;j++)	printf("*");  // 输出每一行的“*”
      printf("\n");     //输完每一行后换行
     }
   return 0;
}
