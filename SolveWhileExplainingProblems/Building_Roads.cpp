/*
  * Gonna basically use DSU, to find the components.
  * We can perform dfs to get the number of components as well.
  * Just a reminder. Num of Components = number of times we've to perform dfs
  * Also, since it's been a while since I've practiced dfs, i'm gonna write the code
  * void dfs(int node, vector<vector<int>>&adj, vector<bool>&vis) {
  *   vis[node] = true;
  *   for (int i:adj[node]) {
  *     if (vis[i]) continue;
  *     dfs(i, adj, vis);
  *   }
  * }
*/

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

class DSU {
public:
  vector<int> parent;
  vector<int> size;

  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  // vector<vector<int>> adj(n);
  // for (int i = 0; i < m; i++) {
  //   int a, b;
  //   cin >> a >> b;
  //   a--; b--;
  //   adj[a].pba(b);
  //   adj[b].pba(a);
  // }
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    dsu.union_sets(a, b);
  }
  vector<int> par;
  for (int i = 0; i < n; i++) {
    if (dsu.parent[i] == i) par.pba(i);
  }
  cout << par.size() - 1 << endl;
  for (int i = 1; i < par.size(); i++) {
    cout << par[i - 1] + 1 << " " << par[i] + 1 << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}