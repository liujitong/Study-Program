#include <bits/stdc++.h>
using namespace std;
const int N=10010;

deque<int> q[N];
int main()
{        ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int Q, m;
    cin >> Q>>m;
    string op;
    int a, x;
  while(Q--)
  {
   cin>>op;
        if (op == "push_back") {
            cin >> a >> x;
            q[a].push_back(x);
        } else if (op == "pop_back") {
            cin >> a;
            if (q[a].size()) {
                q[a].pop_back();
            }
        } else if (op == "push_front") {
            cin >> a >> x;
            q[a].push_front(x);
        } else if (op == "pop_front") {
            cin >> a;
            if (q[a].size()) {
                q[a].pop_front();
            }
        } else if (op == "size") {
            cin >> a;
            cout << q[a].size() << '\n';
        } else if (op == "front") {
            cin >> a;
            if (q[a].size()) {
                cout << q[a].front() << '\n';
            }
        } else {
            cin >> a;
            if (q[a].size()) {
                cout << q[a].back() << '\n';
            }
        }
  }
  // 请在此输入您的代码
  return 0;
}