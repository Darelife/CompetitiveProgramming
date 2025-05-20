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
  int m, x;
  cin >> m >> x;
  vint c(m), h(m);
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> h[i];
  }
  int tot = accumulate(h.begin(), h.end(), 0);
  vint dp(tot + 1, 1e18);
  dp[0] = 0;

  // knapsack stuff 
  for (int i = 0; i < m; i++) {
    for (int j = tot; j >= h[i]; j--) {
      dp[j] = (dp[j - h[i]] + c[i] <= i * x) ? min(dp[j], dp[j - h[i]] + c[i]) : dp[j];
    }
  }

  for (int i = tot; i >= 0; i--) {
    if (dp[i] != 1e18) {
      cout << i << endl;
      return;
    }
  }
  cout << 0 << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}