#include<stdio.h>
int main()
#define PI 3.14
{
	float yzdmj,yzbmj,yztj;
	int r,h;
	scanf("%d %d",&r,&h);
	yzdmj=2*PI*r*r; //圆柱底面积
	yzbmj=yzdmj+PI*2*r*h;//圆柱表面积
	yztj=PI*r*r*h;//圆柱体积
	printf("圆柱底面积为：%.2f\n圆柱表面积为:%.2f\n圆柱体积为：%.2f\n",yzdmj,yzbmj,yztj);
	return 0;
}
//202212080刘纪彤

