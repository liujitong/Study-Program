#include<bits/stdc++.h>
using namespace std;
signed main(){
    stack<char>st;
    string s;
    cin >> s;
    int flag = 0;
    for(int i = 0 ; i < s.size() ; i ++){
      if(s[i] == ')') {
        if(st.size() > 0 && st.top() == '(') st.pop();
        else {
          flag = 1; 
          break ;
        }
      } else if(s[i] == ']'){
        if(st.size() > 0 && st.top() == '[') st.pop();
        else {
          flag = 1; 
          break ;
        }
      } else if(s[i] == '}'){
          if(st.size() > 0 && st.top() == '{') st.pop();
          else {
            flag = 1; 
            break ;
          }
      } else st.push(s[i]);
    }
    if(flag == 1 || st.size() > 0) cout << "N\n";
    else cout << "Y\n";
  return 0;
}