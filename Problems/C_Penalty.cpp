#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;

const int inf = 1e9 + 5;

void solve() {
  string s;
  cin >> s;
  int ans = 9;

  int a = 0, b = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (s[i] == '1' || s[i] == '?')
        a++;
    } else {
      if (s[i] == '1')
        b++;
    }
    if (a > b + (10 - i) / 2) {
      ans = min(ans, i);
    } else if (b > a + (9 - i) / 2) {
      ans = min(ans, i);
    }
  }

  a = 0, b = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (s[i] == '1')
        a++;
    } else {
      if (s[i] == '1' || s[i] == '?')
        b++;
    }
    if (a > b + (10 - i) / 2) {
      ans = min(ans, i);
    } else if (b > a + (9 - i) / 2) {
      ans = min(ans, i);
    }
  }

  cout << ans + 1 << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}