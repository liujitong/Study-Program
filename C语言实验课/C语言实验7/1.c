#include <stdio.h>
int main()
{
	char string[100],Le;
 	int count(char s[]);
 	printf("input string:\n");
	gets(string);        //输入字符串
 	Le=count(string);            //调用count函数
 	printf("大写字母有%d个",Le);
	return 0;
}
int count(char s[])        
{
	int sum=0,i;
 	for (i=0;s[i]!='\0';i++)
	 if (s[i]>='A' && s[i]<='Z')
		 sum++;
  return sum;
}
