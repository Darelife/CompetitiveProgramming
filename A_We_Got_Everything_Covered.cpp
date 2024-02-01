#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void testcase() {
  int n, k;
  cin >> n >> k;
  // get the alphabet in lowercase associated with the index
  string ans = "";
  string s = "";
  char c = 'a';
  for (int i = 0; i < k; i++) {
    s += c;
    c++;
  }
  for (int i = 0; i < n; i++) {
    ans += s;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}