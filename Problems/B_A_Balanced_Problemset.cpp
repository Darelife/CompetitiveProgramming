#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Solution was hacked and a test case was added which made the solution fail
// (TLE) (Time Limit Exceeded)
// We had to use a square root trick to pass the test case
// The square root trick is to iterate from 1 to sqrt(x) and check if x / i >= n
// and x % i == 0

static void testcase() {
  ll x, n;
  cin >> x >> n;
  ll ans = 1;
  for (ll i = 0; i < x; i++) {
    if (x / (i + 1) >= n && x % (i + 1) == 0) {
      ans = i + 1;
    }
    if (x / (i + 1) < n) {
      break;
    }
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