#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
  int m;
  cin>>m;
  queue<string> qv,qq;
  for(int i=0;i<m;i++)
  {
    string OP;
    string name;
    string level;
    cin>>OP;
    if(OP=="IN")
    {
    cin>>name;
    cin>>level;
    if(level=="V")
    {
      qv.push(name);
    }
    else qq.push(name);
    }
    if(OP=="OUT")
    {
    cin>>level;
    if(level=="V") qv.pop();
    else qq.pop();
    }
  }
  while(!qv.empty())
  {
    cout<<qv.front()<<endl;
    qv.pop();
  }//先输出VIP
  while(!qq.empty())
  {
    cout<<qq.front()<<endl;
    qq.pop();
  }//输出不是VIP的
  // 请在此输入您的代码
  return 0;
}