#include<stdio.h>
int main()
{
    int x;
    int Letter=0;
    int letter=0;
    int space=0;
    int shu=0;
    int other=0;
    char c[3][80];
    for(int i=0;i<3;i++)
    {
      gets(c[i]);
    }
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<80;j++)
      {
        if(c[i][j]==' ') space++;
        else if(c[i][j]>='A'&&c[i][j]<='Z') Letter++;
        else if(c[i][j]>='a'&&c[i][j]<='z') letter++;
        else if(c[i][j]>='0'&&c[i][j]<='9') shu++;
        else other++;
        
      }
      printf("%d:daxie:%d\nxiaoxie:%d\nkongge:%d\nshuzi:%d\nqita:%d\n",i,Letter,letter,space,shu,other);
    }
}//2022212088刘智钰