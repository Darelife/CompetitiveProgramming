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

void dfs(int node, vector<vector<int>> &adj, int par, vector<int> &c, vector<int> &ans) {
  int res = c[node];
  for (auto v:adj[node]) {
    if (v != par) {
      dfs(v, adj, node, c, ans);
      res &= c[v];
    }
  }
  ans[node] = res;
}

void solve() {
  int n;
  cin >> n;
  int root;
  vint c(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    c[i] = b;
    if (a == -1) {root = i; continue;}
    a--;
    adj[a].pba(i); // dir = parent to child
  }

  vector<int> ans(n, 1);
  dfs(root, adj, -1, c, ans);

  int flag = 1;
  for (int i = 0; i<n; i++) {
    if (i!=root && ans[i] == 1) {
      flag = 0;
      cout << i+1 << " ";
    }
  }
  if (flag) cout << -1;
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}