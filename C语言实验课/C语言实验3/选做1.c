#include<stdio.h>
#include<stdlib.h>
int main()
{
	int choose;
	printf("1����ΪʲôҪ���Ϸ� \n2 ʲô���ǲ��õ��? \n3 ��������ȥ����԰�棬����԰�ܽ�������·��û���ߴ�Ϊ��ȴ�ܵ�����Ŀ�ĵأ�");
	scanf("%d",&choose);
	system("cls");
	switch(choose)
	{
	
	case 1:printf("��·��");break;
    case 2:printf("�����");break;
    case 3:printf("���ĵ綯��߳�����������");break;
}
return 0;
}
