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

#define v vector

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> c(n);
  for (int i = 0; i < n; i++) cin >> c[i];

  vector<vector<int>> cost(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> cost[i][j];

  int INF = 1e18;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, INF)));

  for (int color = 1; color <= m; color++) {
    dp[n][k][color] = 0;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int b = 0; b <= k; b++) {
      for (int preC = 0; preC <= m; preC++) {

        int ans = INF;
        if (c[i] == 0) {
          for (int curC = 1; curC <= m; curC++) {

            int paintCost = (c[i] == 0) ? cost[i][curC - 1] : 0;
            int newBeauty = (curC != preC ? b + 1 : b);
            if (newBeauty > k) continue;

            ans = min(ans, dp[i + 1][newBeauty][curC] + paintCost);
          }
        } else {
          int curC = c[i];
          int paintCost = (c[i] == 0) ? cost[i][curC - 1] : 0;
          int newBeauty = (curC != preC ? b + 1 : b);
          if (newBeauty > k) continue;

          ans = min(ans, dp[i + 1][newBeauty][curC] + paintCost);
        }
        dp[i][b][preC] = ans;
      }
    }
  }

  cout << (dp[0][0][0] < INF ? dp[0][0][0] : -1) << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}