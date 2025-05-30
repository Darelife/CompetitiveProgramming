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

// struct node {
//   int u, s;
// };

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vint s(n);
  vcin(s, n);

  vector<vector<int>> adj(n, vector<int>(n, 0));
  for (int _ = 0; _ < k; _++) { // made it _ cuz i was thinking of rust and python lol
    int a, b, s;
    cin >> a >> b >> s;

    a--;
    b--;
    // node t = { b, s };
    adj[a][b] = s;
  }

  vector<vector<int>> dp((1 << 18), vector<int>(18, -1));

  // base case, picking only 1 dish
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = s[i];
  }

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int last = 0; last < n; last++) {
      if (dp[mask][last] == -1) continue;
      for (int next = 0; next < n; next++) {
        if (mask & (1 << next)) continue; // already picked this element

        int t = mask | (1 << next);
        dp[t][next] = max(dp[t][next], dp[mask][last] + adj[last][next] + s[next]);
      }
    }
  }

  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (__builtin_popcount(mask) != m) continue;

    for (int last = 0; last < n; ++last) {
      ans = max(ans, dp[mask][last]);
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}