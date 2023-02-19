#include<stdio.h>
int main()
{
	int score;//声明成绩
	scanf("%d",&score);
	if(score<60) 	printf("bad"); 
	if(score>=60&&score<80) 	printf("middle");
	if(score>=80&&score<90) 	printf("good");
	if(score>=90) 	printf("excellent");
	return 0;
 } //2022212080刘纪彤 
