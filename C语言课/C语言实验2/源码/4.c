#include<stdio.h>
int main()
#define PI 3.14
{
	float yzdmj,yzbmj,yztj;
	int r,h;
	scanf("%d %d",&r,&h);
	yzdmj=2*PI*r*r; //Բ�������
	yzbmj=yzdmj+PI*2*r*h;//Բ�������
	yztj=PI*r*r*h;//Բ�����
	printf("Բ�������Ϊ��%.2f\nԲ�������Ϊ:%.2f\nԲ�����Ϊ��%.2f\n",yzdmj,yzbmj,yztj);
	return 0;
}
//202212080����ͮ

