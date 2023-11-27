#include<bits/stdc++.h>
using namespace std;
bool iszhi(long long x)
{
    for(int i=2;i<x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long x;
        cin>>x;
        int count=0;
        for(long long  i=0;i<x;i++)
        {
            if(iszhi((i^x))) count++;
        }
        cout<<count<<endl;
    }
}