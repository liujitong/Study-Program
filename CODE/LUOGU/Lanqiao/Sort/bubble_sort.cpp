//冒泡排序算法
#include <iostream>
using namespace std;
long long bubble_sort(long long *num,long long n)
{
  for(long long i=0;i<n;i++)
  {
    for(long long j=0;j<n-i-1;j++)
    {
      if(num[j]>num[j+1])
      {
        long long temp=num[j];
        num[j]=num[j+1];
        num[j+1]=temp;
      }
    }
  }
  return 1;
}
int main()
{
  long long num[100000];
  long long n;
  cin>>n;
  for(long long i=0;i<n;i++)
  {
    cin>>num[i];
  }
  bubble_sort(num,n);
  for(long long i=0;i<n-1;i++)
  {
    cout<<num[i]<<' ';
  }
  cout<<num[n-1];
  // 请在此输入您的代码
  return 0;
}