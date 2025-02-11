#include <bits/stdc++.h>
using namespace std;

int main() {
  // your code goes here
  string s;
  cin >> s;
  // stack<char> st;
  stack<int> st;
  int ans = 0;
  map<char, int> m;
  m['H'] = 1;
  m['C'] = 12;
  m['O'] = 16;
  m[')'] = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') st.push(-1);
    else if (s[i] == ')') {
      int temp = 0;
      while (st.top() != -1) {
        temp += st.top();
        st.pop();
      }
      st.pop();
      st.push(temp);
    } else if (s[i] >= '2' && s[i] <= '9') {
      int temp = st.top();
      st.pop();
      temp *= (s[i] - '0');
      st.push(temp);
    } else st.push(m[s[i]]);
  }

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  cout << ans << endl;
  return 0;
}