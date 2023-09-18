#include<bits/stdc++.h>
using namespace std;
signed main()
{
  string str;
  cin>>str;
  int flag=0;
  stack<char>st1;//注意此处需要用char
  for(int i=0;i<str.size();i++)
  {
    if(str[i]== '}')
    {
      if(st1.size()==0&&st1.top()!='{') 
      {
        flag=1;
        break;
      }
      else 
      {
        st1.pop();
      }
    }
    else if(str[i]==']')
    {
      if(st1.size()==0&&st1.top()!='[') 
      {
        flag=1;
        break;
      }
      else 
      {
        st1.pop();
      }
    }
    else if(str[i]==')')
    {
      if(st1.size()==0&&st1.top()!='(') 
      {
        flag=1;
        break;
      }
      else 
      {
        st1.pop();
      }
    }
    else st1.push(str[i]);
    }
    //输出区域
    if(st1.size()==0&&flag==0) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
  // 请在此输入您的代码
  return 0;
}