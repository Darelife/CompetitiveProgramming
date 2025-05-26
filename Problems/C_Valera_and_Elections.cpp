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

int dfs(int node, int parent, vector<vector<int>> &adj, vector<int>&bad, vector<int>&ans) {
  if (bad[node]==1) {
    ans[node]++;
  }
  for (int i:adj[node]) {
    if (i == parent) continue;
    ans[node] += dfs(i, node, adj, bad, ans);
  }
  return ans[node];
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n+1);
  vector<int> bad(n+1, 0);
  for (int i = 0; i<n-1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].pba(y);
    adj[y].pba(x);
    if (z == 2) {
      bad[x] = 1;
      bad[y] = 1;
    }
  }

  vector<int> ans(n+1, 0);

  dfs(1, -1, adj, bad, ans);

  vector<int> finalAns;
  for (int i = 1; i<=n; i++) {
    if (ans[i] == 1) finalAns.pba(i);
  }
  cout << finalAns.size() << endl;
  vpin(finalAns);
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}