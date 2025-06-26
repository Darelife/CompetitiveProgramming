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
  vector<int> minw;

  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    minw.resize(n, LLONG_MAX);
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

  void union_sets(int x, int y, int w) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    minw[x] = min({ minw[x], minw[y], w });
  }
};

struct edge {
  int u, v, w;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<edge> e(m);
  for (auto& [u, v, w] : e) {
    cin >> u >> v >> w;
    u--; v--;
  }

  sort(e.begin(), e.end(), [](edge& a, edge& b) {
    return a.w < b.w;
    });

  DSU dsu(n);
  int ans = LLONG_MAX;

  for (auto& ed : e) {
    auto [u, v, w] = ed;
    dsu.union_sets(u, v, w);
    if (dsu.find(0) == dsu.find(n - 1)) {
      int mw = dsu.minw[dsu.find(0)];
      ans = min(ans, mw + w);
    }
  }

  if (ans == LLONG_MAX) cout << -1 << endl;
  else cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}