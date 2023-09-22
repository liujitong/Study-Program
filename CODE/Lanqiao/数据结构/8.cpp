#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    queue<int>qu;
    for(int i=0;i<q;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x;
            qu.push(x);
        }
        if(op==2)
        {
            qu.pop();
        }
        if(op==3)
        {
            cout<<qu.front()<<" "<<qu.back()<<endl;
        }
    }

}