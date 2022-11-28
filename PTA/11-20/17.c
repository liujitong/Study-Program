#include<stdio.h>
int main()
{
	int grade;
	char level;
	scanf("%d",&grade);
	if(grade>=90) level = 'A';
	if(grade<90&&grade>=80) level = 'B';
	if(grade<80&&grade>=70) level = 'C';
	if(grade<70&&grade>=60) level = 'D';
	if(grade<60) level = 'E';
	printf("%c",level);
	return 0;
 } 
/*本题要求编写程序将一个百分制成绩转换为五分制成绩。转换规则：

大于等于90分为A；
小于90且大于等于80为B；
小于80且大于等于70为C；
小于70且大于等于60为D；
小于60为E。
输入格式:
输入在一行中给出一个整数的百分制成绩。

输出格式:
在一行中输出对应的五分制成绩。

输入样例:
90
输出样例:
A
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/