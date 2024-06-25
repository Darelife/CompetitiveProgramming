#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define la(i, a, n) for (int i = a; i < n; i++)      // loop around
#define rla(i, n) for (int i = n; i >= 0; i--)       // reverse loop around
#define ela(i, a, n) for (int i = a; i <= n; i++)    // Equal Loop Around
#define lasqr(i, n) for (int i = 1; i * i <= n; i++) // loop around square root
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vi;

const int inf = 1e9 + 5;

void solve() {
  string s;
  cin >> s;

  int ans = s.size();
  int flag1 = 0; // last digit is 5
  int flag2 = 0; // last digit is 0
  for (int i = s.size() - 1; i >= 0; i--) {
    if (flag1 == 0 && s[i] == '5') {
      flag1 = 1;
    } else if (flag1 == 1 && (s[i] == '2' || s[i] == '7')) {
      ans = min(ans, (int)s.size() - 1 - i);
      cout << ans - 1 << endl;
      break;
    }
    if (flag2 == 0 && s[i] == '0') {
      flag2 = 1;
    } else if (flag2 == 1 && (s[i] == '0' || s[i] == '5')) {
      ans = min(ans, (int)s.size() - 1 - i);
      cout << ans - 1 << endl;
      break;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}