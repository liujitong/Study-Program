#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,p;
        cin>>a>>p;
        int coures=0;
        coures+=a;
        if(p<16) coures-=10;
        if(p>20) coures-=1*(p-20);
        if(coures<=0) cout<<"0"<<endl;
        else cout<<coures<<endl;
    }    
}