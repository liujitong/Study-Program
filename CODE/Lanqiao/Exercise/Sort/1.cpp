#include<bits/stdc++.h>

using namespace std;

string ch;
int n,x;

int main() {
    cin>>n>>x>>ch;
    sort(ch.begin(),ch.end());
    if(ch[0]!=ch[x-1]) {
        cout<<ch[x-1];
        return 0;
    }
    cout<<ch[0];
    if(ch[x]!=ch[n-1]) {
        for(int i=x;i<n;i++) {
            cout<<ch[i];
        }
    }
    else {
        for(int i=0;i<(n-1)/x;i++) {
            cout<<ch[n-1];
        }
    }
}