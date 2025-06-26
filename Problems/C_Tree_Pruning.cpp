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

void dfs(int u, int par, vint& maxD, vint& d, int depth, vector<vint>& adj, int& md) {
  md = max(md, depth);
  d[u] = depth;
  maxD[u] = max(maxD[u], depth);

  for (int v : adj[u]) {
    if (v == par) continue;
    dfs(v, u, maxD, d, depth + 1, adj, md);
    maxD[u] = max(maxD[u], maxD[v]);
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1); //1 based indexing, i don't want any headaches
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pba(b);
    adj[b].pba(a);
  }

  vector<int> maxD(n + 1, 0), d(n + 1, 0);
  int md = 1;
  dfs(1, -1, maxD, d, 1, adj, md);

  vector<int> a1(md + 1), a2(md + 1);
  for (int i = 1; i <= n; i++) {
    a1[maxD[i]]++;
    a2[d[i]]++;
  }
  for (int i = 1; i <= md; i++) {
    a1[i] += a1[i - 1];
    a2[i] += a2[i - 1];
  }

  int ans = INT_MAX;
  for (int i = 1; i <= md; i++) {
    ans = min(ans, a1[i - 1] + a2[md] - a2[i]);
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}