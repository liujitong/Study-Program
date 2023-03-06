#include<stdio.h>
int main()
{ int i,j,z;
  for (i=1;i<=9;i++)
	 {for (j=1;j<=10-i;j++)	    printf(" ");     //输出之前的空格
	  for (j=1;j<=i;j++)	printf("%d",j);  // 输出左半边
      for (z=i-1;z>0;z--) printf("%d",z);
      printf("\n");     //输完每一行后换行
     }
   return 0;
}
