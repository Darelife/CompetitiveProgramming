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
  int n, k, o;
  cin >> n >> k >> o;

  vint a(n);
  vcin(a, n);
  vint b(k);
  vcin(b, k);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  for (int i = 0; i < n; i++) dp[i][k] = 1e18;

  dp[n][k] = 0;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = k - 1; j >= 0; j--) {
      int cost = abs(a[i] - b[j]) + abs(b[j] - o);
      dp[i][j] = min(dp[i][j + 1], max(cost, dp[i + 1][j + 1]));
    }
  }
  cout << dp[0][0] << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}