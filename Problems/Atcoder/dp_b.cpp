#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define f(i, a, b) for (int i = a; i < b; i++)
#define pba push_back

typedef vector<int> vint;
#define vcin(vint, n) f(i, 0, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;

#define endl '\n'
const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vint h(n);
  vcin(h, n);
  // vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
  vector<int> dp(n + 1, INT_MAX);
  // dp[n][0] = 0;
  // dp[n][1] = 0;
  // dp[n - 1][0] = abs(h[n - 1] - h[n - 2]);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0 && (i - j <= k); j--) {
      dp[i] = min(dp[i], abs(h[j] - h[i]) + dp[j]);
    }
  }
  // cout << min(dp[1][0], dp[1][1]) << endl;
  cout << dp[n - 1] << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}
