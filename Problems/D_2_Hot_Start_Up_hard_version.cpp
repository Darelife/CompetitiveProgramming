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

  // let's take dp[i][j] = the minimum time for i such that the last element run on the cpu we
  //  didn't use last was j

  vint a(n);
  vcin(a, n);

  for (int i = 0; i < n; i++) a[i] -= 1;

  // vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e18));
  vector<int> dp(k + 1, 1e18);
  vint c(k), h(k);
  vcin(c, k); vcin(h, k);

  dp[k] = c[a[0]];

  for (int i = 1; i < n; i++) {
    vector<int> dp2(k + 1, 1e18);
    for (int j = 0; j <= k; j++) {
      dp2[j] = (a[i - 1] == a[i]) ? min(dp2[j], dp[j] + h[a[i]]) : min(dp2[j], dp[j] + c[a[i]]);
      dp2[a[i - 1]] = (a[i] == j) ? min(dp2[a[i - 1]], dp[j] + h[a[i]]) : min(dp2[a[i - 1]], dp[j] + c[a[i]]);
    }
    dp = dp2;
  }

  int ans = LLONG_MAX;
  for (int i = 0; i <= k; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}