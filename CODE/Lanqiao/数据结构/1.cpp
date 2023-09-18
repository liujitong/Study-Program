#include <iostream>
#include <stack>
using namespace std;
int main()
{
  stack<int>st;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int l;
    cin>>l;
    if(l==0)
    {
      if(!st.empty())
      {
        st.pop();
      }
    }
    else 
    {
      st.push(l);
    }
  }
  while(!st.empty())
  {    
    cout<<st.top()<<endl;
    st.pop();
  }
  // 请在此输入您的代码
  return 0;
}