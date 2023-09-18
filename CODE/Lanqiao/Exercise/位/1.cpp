#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int a[1000000];
    int i=0;
    while(n!=0)
    {
        a[i]=n%2;
        n=n/2;
        i++;
    }
    int length=i;
    int i1=-1;
    for(int i=0;i<length;i++)
    {
        if(a[i]==1) 
        {
            i1=i;
            break;
        }
    }
    int i2=-1;
    for(int i=length;i>0;i--)
    {
        if(a[i]==1)
        {
            i2=i;
            break;
        }
    }
    cout<<i2-i1<<endl;
  // 请在此输入您的代码
  return 0;
}