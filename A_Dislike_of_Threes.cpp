#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void testcase() {
  int k;
  cin >> k;
  int cnt = 0;
  for (int i = 1; i <= 1666; i++) {
    if (i % 3 == 0 || i % 10 == 3)
      continue;
    cnt++;
    if (cnt == k) {
      cout << i << '\n';
      return;
    }
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