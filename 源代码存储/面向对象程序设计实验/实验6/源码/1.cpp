#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
T maxi(T a,T b)
{
    return a>b?a:b;
}
int main()
{
  int a=5,b=6,c;
  c=max(a,b);
  cout<<"整型c=max(a,b)为："<<c<<endl;
  string d="asd",e="dfg",f;
  f=max(d,e);
  cout<<"字符串 f=max(d,e)为："<<f<<endl;
  return 0;
}
