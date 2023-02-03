#include<stdio.h>
#include<string.h>
#define GPS_ARRAY_SIZE 1000
void retime(char data[],int time[]);//返回时间专用

int main()
{
  char data[GPS_ARRAY_SIZE];//接收GPS数据
  char end[]="END";//用以判断最后输入的END
  int time[3]={0};//初始化时间
  do
  {
    scanf("%s",data);
    retime(data,time);
  }while(strcmp(data,end)!=0);//strcmp函数为一个string库的字符串处理函数，判断字符串是否相等
    printf("%02d:%02d:%02d\n",time[0],time[1],time[2]);//输出时分秒
    return 0;
}
void retime(char data[],int time[])
{
 int  test1=0;//校验值1
 int test2;//校验值2
 int i;//循环用
 if(data[0]=='$'&&data[1]=='G'&&data[2]=='P'&&data[3]=='R'&&data[4]=='M'&&data[5]=='C'&&data[6]!='\0')//确定输入为有效的GPS数据
 {
  for(i=1;data[i]!='*';i++)
  {
    test1=test1 ^ data[i];
  }
  char m1=data[i+1];
  char m2=data[i+2];
  
  int d1,d2;
  if(m1>='A'&&m1<='F') d1=10+(m1-'A');
  if(m2>='A'&&m1<='F') d2=10+(m2-'A');
  if(m1>='0'&&m1<='9') d1=m1-'0';
  if(m2>='0'&&m2<='9') d2=m2-'0';
  test2=d1*16+d2;//十六进制转换
 
}
  
  for(i=7; data[i]!='*'; i++)
  { //从第一个逗号后面开始遍历
      if(data[i]==',') break;
  }
  
  if(data[i+1]=='A'&&test1==test2)//确认已经定位
  {
    int hour;
                hour = 10 * (data[7] - '0') + (data[8] - '0');
                time[0] = (hour + 8) % 24;
                time[1] = 10 * (data[9] - '0') + (data[10] - '0') ;
                time[2] = 10 * (data[11] - '0') + (data[12] - '0');
  }//UTC时间转换成为北京时间
}