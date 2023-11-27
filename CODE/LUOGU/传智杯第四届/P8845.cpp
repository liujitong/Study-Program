#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if((x==1&&y==2)||(x==2&&y==1)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}