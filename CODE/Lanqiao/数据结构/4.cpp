#include <bits/stdc++.h>
using namespace std;
int main()
{
  queue<int>que;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
  int x;
  cin>>x;
  if(x==2)
  {
    if(que.empty())    cout<<"lan"<<endl;
    else que.pop();
  }
  else if (x==3)
  {
    if(que.empty()) cout<<"qiao"<<endl;
    else cout<<que.front()<<endl;
  }
  else if(x==1)
  {
    int p;
    cin>>p;
    que.push(p);
  }
  else cout<<que.size()<<endl;
  }
  // 请在此输入您的代码
  return 0;
}