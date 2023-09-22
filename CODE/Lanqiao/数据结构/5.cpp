#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<pair<int ,int >>misson;
    priority_queue<int> pq;
    int n;
    int x;
    int a[100];
    cin>>n;
    cin>>x;
    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        misson.push({i,l});
        pq.push(l);
    }
    int time =0;
    while(1)
    {
        int w=misson.front().second;
        if(w==pq.top())
        {
            time++;
            if(misson.front().first==x)
            {
                cout<<time<<endl;
                return 0;
            }
            misson.pop();
            pq.pop();
        }
        else
        {
            misson.push(misson.front());
            misson.pop();
        }
    }
  // 请在此输入您的代码
  return 0;
}