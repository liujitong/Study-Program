//归并排序算法
#include <iostream>
using namespace std;
//合并
void Merge(int *A,int l,int mid,int r)
{
  int *B=new int[r-l+1];
  int i=l;
  int j=mid+1;
  int k=0;
  while(i<=mid&&j<=r)
  {
    if(A[i]<=A[j]) B[k]=A[i++];
    else B[k]=A[j++];
    k++;
  } 
  while(i<=mid) B[k++]=A[i++];
  while(j<=r) B[k++]=A[j++];
  for(int i=l,k=0;i<=r;i++)
  {
    A[i]=B[k++];
  }
  delete[] B;
}
//合并排序算法
void mergeSort(int *num ,int l,int r)//l和r分别代表这个数组的左值和右值
{
  if(l==r) return ;
  if(l<r)
  {
    int mid=(l+r)/2;
    mergeSort(num,l,mid);
    mergeSort(num,mid+1,r);
    Merge(num,l,mid,r);
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
  mergeSort(num,0,n-1);
  for(long long i=0;i<n-1;i++)
  {
    cout<<num[i]<<' ';
  }
  cout<<num[n-1];
  // 请在此输入您的代码
  return 0;
}