#include<stdio.h>
#include<stdlib.h>
int main()
{
	int choose;
	printf("1大雁为什么要向南飞 \n2 什么人是不用电的? \n3 阿呆开车去动物园玩，动物园很近，他的路并没有走错，为何却总到不了目的地？");
	scanf("%d",&choose);
	system("cls");
	switch(choose)
	{
	
	case 1:printf("走路慢");break;
    case 2:printf("缅甸人");break;
    case 3:printf("开的电动玩具车，他在外面");break;
}
return 0;
}
