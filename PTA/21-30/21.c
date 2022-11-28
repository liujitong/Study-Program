#include<stdio.h>
#include<stdlib.h>
int main()
{
  int speed;
  scanf("%d",&speed);
  if(speed<=60) printf("Speed: %d - OK",speed);
  else printf("Speed: %d - Speeding",speed);
  system ("Pause");//注意此函数应加入头文件<stdlib.h>,就不会报错了。
  return 0;
}/*模拟交通警察的雷达测速仪。输入汽车速度，如果速度超出60 mph，则显示“Speeding”，否则显示“OK”。

输入格式：
输入在一行中给出1个不超过500的非负整数，即雷达测到的车速。

输出格式：
在一行中输出测速仪显示结果，格式为：Speed: V - S，其中V是车速，S或者是Speeding、或者是OK。

输入样例1：
40
输出样例1：
Speed: 40 - OK
输入样例2：
75
输出样例2：
Speed: 75 - Speeding
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/