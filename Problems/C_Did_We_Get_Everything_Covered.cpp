#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void testcase() {
  int n, k, m;
  cin >> n >> k >> m;
  string s;
  cin >> s;
  bool ans = true;
  for (int i = 0; i < k; i++) {
    if (count(s.begin(), s.end(), 'a' + i) < n) {
      ans = false;
      cout << "NO\n";
      string a = "";
      for (int j = 0; j < n; j++) {
        a += 'a' + i;
      }
      cout << a << '\n';
      return;
    }
  }
  if (ans) {
    cout << "YES\n";
    return;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}