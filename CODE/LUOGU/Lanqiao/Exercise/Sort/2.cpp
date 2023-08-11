#include<bits/stdc++.h>
using namespace std;
//寻找每次的基准元素
int Particial(long long  *R,int l, int r)
{
    int i=l;
    int j=r;
    int pivot = R[l];
    while(i<j)
    {
        while(i<j&&R[j]>pivot) j--;//向左扫描，找出一个小于等于pivot的数
        if(i<j)
        {
            swap(R[i++],R[j]);
        }
        while(i<j&&R[i]<=pivot) i++;//向右扫描，找出一个大于pivot的书
        if(i<j)
        {
            swap(R[i],R[j--]);
        }
    }
    return i;//返回基准元素i
}
void quickSort(long long *num,int l ,int r)
{
    if(l<r)
    { 
    int mid = Particial(num,l,r);
    quickSort(num,l,mid-1);
    quickSort(num,mid+1,r);
    }
}
long long min(long long a,long long b)
{
    if(a>b) return b;
    else return a;

}
int main()
{
    long long n;
    cin>>n;
    long long a[100000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    long long ans=1e9;
    for(int i=0;i<n-1;i++)
    {
        ans=min(a[i+1]-a[i],ans);
    }
    cout<<ans;
}