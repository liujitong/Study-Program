#include <stdio.h>
int main()
{
	char string[100],Le;
 	int count(char s[]);
 	printf("input string:\n");
	gets(string);        //�����ַ���
 	Le=count(string);            //����count����
 	printf("��д��ĸ��%d��",Le);
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
