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

// void dfs(int node, int par, vector<vector<int>>&adj, int& val, vector<int>&c, int ans) {
//   for (auto v: adj[node]) {
//     if (v != par) {
//       dfs(v, node, adj, val, c, ans);
//       if (val != c[node]) {
//         val = -2;
//       }
//       if (val == -1 && c[node] != c[par]) {
//         val = c[node];
//       }
//     }
//   }
// }

void solve() {
  int n;
  cin >> n;
  // vector<vector<int>> adj(n);
  // for (int i = 0; i<n-1; i++) {
  //   int x, y;
  //   cin >> x >> y;
  //   x--; y--;
  //   adj[x].pba(y);
  //   adj[y].pba(x);
  // }
  
  // vint c(n);
  // vcin(c, n);
  // int val = -1;
  // dfs(0, -1, adj, val, c);

  // if (val == -2) {
  //   cout << "NO" << endl;
  //   return;
  // }
  // else return 
  vector<pair<int, int>> edges;
  for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      edges.emplace_back(u, v);
  }

  vint c(n);
  vcin(c, n);

  vector<pair<int, int>> diff_edges;
  for (auto &[u, v] : edges) {
      if (c[u] != c[v]) {
          diff_edges.emplace_back(u, v);
      }
  }

  if (diff_edges.empty()) {
    cout << "YES" << endl << '1' << endl;
    return;
  }

  auto [a, b] = diff_edges[0];

  int flaga = 1;
  for (auto &[u, v] : diff_edges) {
    if (u != a && v != a) flaga = 0;
  }

  int flagb = 1;
  for (auto &[u, v] : diff_edges) {
    if (u != b && v != b) flagb = 0;
  }

  if (flaga) {
      cout << "YES"  << endl << a + 1 << endl;
  } else if (flagb) {
      cout << "YES" << endl << b + 1 << endl;
  } else {
      cout << "NO" << endl;;
  }

}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}