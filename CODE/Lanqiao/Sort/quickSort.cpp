#include<iostream>
#include<algorithm>
using namespace std;
//寻找每次的基准元素
int Particial(int *R,int l, int r)
{
    int i=l;
    int j=r;
    int pivot = R[l];
    while(i<j)
    {
        while(i<j&&R[j]>pivot) j--;//向左扫描，找出一个小于等于pivot的数
        if(i<j)
        {
            swap(R[i++],R[j]);
        }
        while(i<j&&R[i]<=pivot) i++;//向右扫描，找出一个大于pivot的书
        if(i<j)
        {
            swap(R[i],R[j--]);
        }
    }
    return i;//返回基准元素i
}
void quickSort(int *num,int l ,int r)
{
    if(l<r)
    { 
    int mid = Particial(num,l,r);
    quickSort(num,l,mid-1);
    quickSort(num,mid+1,r);
    }
}
int main()
{
  int num[100000];
  long long n;
  cin>>n;
  for(long long i=0;i<n;i++)
  {
    cin>>num[i];
  }
  quickSort(num,0,n-1);
  for(long long i=0;i<n-1;i++)
  {
    cout<<num[i]<<' ';
  }
  cout<<num[n-1];
  // 请在此输入您的代码
  return 0;
}