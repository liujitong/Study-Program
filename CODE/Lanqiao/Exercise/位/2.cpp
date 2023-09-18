#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int min(int a,long long int k)
{
    if(a<k) return a;
    else return k;
}
int main()
{
  int t;
  long long n,k;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    cin>>n>>k;
    long long  cnt=1;
    k=min(30,k);
    for(int j=0;j<k;j++)
    {
      cnt*=2;
    }
    cout<<min(cnt-1,n)+1<<endl;
  }
  // 请在此输入您的代码
  return 0;
}