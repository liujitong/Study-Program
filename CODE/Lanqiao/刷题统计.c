#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  long long int a,b;
  long  long int n;
  long  long int sum=0;//
  int zhou=1;//周几的标志
  long long int weeks;
  long long int days=0;//天数
  scanf("%lld %lld %lld",&a,&b,&n);
  weeks=n/(5*a+2*b);
  n=n-weeks*(5*a+2*b);
  for(days=0;sum<n;days++)
  {
    if(zhou>7) zhou-=7;
    if(zhou>=1&&zhou<=5) sum+=a;
    if(zhou==6||zhou==7) sum+=b;
    zhou++;
  }
  
  printf("%lld",weeks*7+days);
  return 0;
}