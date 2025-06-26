/*
  * Here's my approach. Im gonna use a DSU,
  * and for each element, i'll first find its root,
  * and then, val[root] = min(c[i], val[root])
  *
  * nevermind, ig i sort of considered it as an
  * undirected graph. basically we know that there will be
  * some sort of a cycle, as there are n vertices, and n edges.
  * And also, after a point, every rat will end up in a cycle.
  * So basically, we'll just have to detect the cycles, and for each cycle,
  * we'll have to find the element with the least cost.
  * Our final answer will be the sum of the costs of these elements
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

void __print(int x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V>& x) { cerr << '{';__print(x.first);cerr << ',';__print(x.second); cerr << '}'; }
template <typename T> void __print(const T& x) { int f = 0;cerr << '{';for (auto& i : x)cerr << (f++ ? "," : ""), __print(i);cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t);if (sizeof...(v)) cerr << ", ";_print(v...); }
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


// class DSU {
// public:
//   vector<int> parent;
//   vector<int> size;

//   DSU(int n) {
//     parent.resize(n);
//     size.resize(n, 1);
//     for (int i = 0; i < n; i++) {
//       parent[i] = i;
//     }
//   }

//   int find(int x) {
//     if (parent[x] != x) {
//       parent[x] = find(parent[x]);
//     }
//     return parent[x];
//   }

//   void union_sets(int a, int b) {
//     a = find(a);
//     b = find(b);
//     if (a != b) {
//       if (size[a] < size[b]) swap(a, b);
//       parent[b] = a;
//       size[a] += size[b];
//     }
//   }
// };


void solve() {
  int n;
  cin >> n;
  vint c(n);
  vcin(c, n);
  vint a(n);
  vcin(a, n);

  for (int i = 0; i < n; i++) a[i]--;

  vector<int> vis(n, 0);
  // 0 = not visited, 1 = visiting, 2 = visited
  int total = 0;

  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    int v = a[u];
    if (vis[v] == 0) {
      dfs(v);
    } else if (vis[v] == 1) {
      int cycle_min = c[v];

      // basically in the entire cycle....if it's 1, that means that we have a cycle
      for (int x = a[v]; x != v; x = a[x]) {
        cycle_min = min(cycle_min, c[x]);
      }

      total += cycle_min;
    }
    vis[u] = 2;
    };

  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      dfs(i);
    }
  }

  cout << total << endl;

  // DSU dsu(n);

  // for (int i = 0; i < n; i++) {
  //   int t = a[i] - 1;
  //   dsu.union_sets(i, t);
  // }

  // vint par;
  // for (int i = 0; i < n; i++) {
  //   if (dsu.parent[i] == i) par.pba(i);
  // }

  // debug(par);

  // vint ans(n, INT_MAX);
  // for (int i = 0; i < n; i++) {
  //   int root = dsu.find(i);
  //   ans[i] = min(ans[i], c[i]);
  // }

  // debug(ans);

  // int tot = 0;
  // for (int i : par) {
  //   tot += ans[i];
  // }
  // cout << tot << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}