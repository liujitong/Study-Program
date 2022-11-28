#include<stdio.h>
#include<math.h>
int main()
{
 int xi[101];//设置一个长度为101的数组；
 int mi,y,z,i;
 int max=0;//最大的幂次
 //定义区
 for(i=0;i<=100;i++)//
 {
    xi[i]=0;
 }
 //遍历数组对数组进行初始化为零
 do
 {
    scanf("%d %d",&mi,&y);
    xi[mi]+=y;
    if(mi>max) max=mi;
 } while (y!=0);
 //将每次输入存储在数组中
for(;max>2&&xi[max]==0;max--)
{

}
if(max>2)
{
    if(xi[max]==0) goto forew;
if(xi[max]==1) printf("x%d",max);//系数为一
else if (xi[max]==-1) printf("-x%d",max);//系数为负一
else printf("%dx%d",xi[max],max);//其他系数

forew:
for(z=max-1;z>1;z--)
{
    if(xi[z]==0) continue;//检测到0跳过
    if(xi[z]>0)//正数情况
    {
    if(xi[z]==1) printf("+x%d",z);
    else printf("+%dx%d",xi[z],z);
    }
    if(xi[z]<0) //负数情况
    {
    xi[z]=-1*(xi[z]);
    if(xi[z]==1) printf("-x%d",z);
    else printf("-%dx%d",xi[z],z);
    }
    
}

}//最高项大于2的情况

if(max==2)
{
    if(xi[2]>0)
    {
    if(xi[2]==1) printf("x2");
    else printf("%dx2",xi[2]);
    }
    if(xi[2]<0)
    {
    xi[2]=-1*(xi[2]);
    if(xi[2]==1) printf("-x2");
    else printf("-%dx2",xi[2]);
    }
}
//此时为最高项为2
if(max==1)
{
    if(xi[1]==-1) printf("-x");
    else if(xi[1]==1) printf("x");
    else printf("%dx",xi[1]);
    if(xi[0]<0)printf("-%d",xi[0]);
    if(xi[0]>0) printf("+%d",xi[0]);
    return 0;
}
//最高项为一的情况
if(max==0)
{
    printf("%d",xi[0]);
    return 0;
}
//最高项为0的情况
if(xi[1]>0)
    {
        if(xi[1]==1) printf("+x");
        else printf("+%dx",xi[1]);
    }
    if(xi[1]<0)
    {
        xi[1]=-1*(xi[1]);
        if(xi[z]==1) printf("-x");
        else printf("-%dx",xi[1]);
    }
//当幂次为1时

if(xi[0]<0)
    {
    printf("%d",xi[0]);
    }
if(xi[0]>0)
    {
    printf("+%d",xi[0]);
    }
}
/*1多项式加法（5分）
题目内容：

一个多项式可以表达为x的各次幂与系数乘积的和，比如：

2x6+3x5+12x3+6x+20

现在，你的程序要读入两个多项式，然后输出这两个多项式的和，也就是把对应的幂上的系数相加然后输出。

程序要处理的幂最大为100。



输入格式:

总共要输入两个多项式，每个多项式的输入格式如下：

每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，所有的系数都是整数。第一行一定是最高幂，最后一行一定是0次幂。

注意第一行和最后一行之间不一定按照幂次降低顺序排列；如果某个幂次的系数为0，就不出现在输入数据中了；0次幂的系数为0时还是会出现在输入数据中。



输出格式：

从最高幂开始依次降到0幂，如：

2x6+3x5+12x3-6x+20

注意其中的x是小写字母x，而且所有的符号之间都没有空格，如果某个幂的系数为0则不需要有那项。



输入样例：

6 2

5 3

3 12

1 6

0 20

6 2

5 3

2 12

1 6

0 20



输出样例：

4x6+6x5+12x3+12x2+12x+40

时间限制：500ms内存限制：32000kb*/