#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    int maxn=-1220;
    int minn=10000;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
		maxn=a[i]>maxn?a[i]:maxn;
		minn=a[i]<minn?a[i]:minn;
    }
    for(int i=0;i<n;i++)
    {
        cout << (int)(100 * ((float)(a[i] - minn) /(float)(maxn - minn)))<<" ";

    }
}