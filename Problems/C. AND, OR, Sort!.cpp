/*
██████╗  █████╗ ██████╗ ███████╗██╗     ██╗███████╗███████╗
██╔══██╗██╔══██╗██╔══██╗██╔════╝██║     ██║██╔════╝██╔════╝
██║  ██║███████║██████╔╝█████╗  ██║     ██║█████╗  █████╗
██║  ██║██╔══██║██╔══██╗██╔══╝  ██║     ██║██╔══╝  ██╔══╝
██████╔╝██║  ██║██║  ██║███████╗███████╗██║██║     ███████╗
╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝╚═╝     ╚══════╝
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'

#define f(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pba push_back
#define sz(x) (int)(x).size()

typedef vector<int> vint;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpint;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define vcin(v, n)         \
  f(i, 0, n) cin >> v[i]

#define vin(v) for (auto &x : v) cin >> x
#define vpin(v)            \
  for (auto x : v)         \
    cout << x << " ";      \
  cout << endl

const int INF = 1e18;
const int MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

void __print(int x) { cerr << x; }
void __print(string x) { cerr << x; }
void __print(char x) { cerr << x; }
void __print(bool x) { cerr << x; }
template<typename T, typename V> void __print(pair<T, V> x) { cerr << "{"; __print(x.first); cerr << ","; __print(x.second); cerr << "}"; }
template<typename T> void __print(T x) { int f = 0; cerr << "{"; for (auto i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

namespace Math {
  int mul(int a, int b, int mod = MOD) {
    return (a % mod * b % mod) % mod;
  }

  int binpow(int a, int b) {
    int res = 1;
    while (b) {
      if (b & 1) res *= a;
      a *= a;
      b >>= 1;
    }
    return res;
  }

  int binpowmod(int a, int b, int mod = MOD) {
    int res = 1;
    while (b) {
      if (b & 1) res = mul(res, a, mod);
      a = mul(a, a, mod);
      b >>= 1;
    }
    return res;
  }

  int inv(int a, int mod = MOD) {
    return binpowmod(a, mod - 2, mod);
  }

  int divide(int a, int b, int mod = MOD) {
    return mul(a, inv(b, mod), mod);
  }
}

class Comb {
public:
  vint fact, ifact;
  int n, mod;

  Comb(int n, int mod = MOD) : n(n), mod(mod) {
    fact.resize(n + 1);
    ifact.resize(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = Math::mul(fact[i - 1], i, mod);

    ifact[n] = Math::inv(fact[n], mod);
    for (int i = n - 1; i >= 0; i--) ifact[i] = Math::mul(ifact[i + 1], i + 1, mod);
  }

  int ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return Math::mul(fact[n], Math::mul(ifact[r], ifact[n - r], mod), mod);
  }
};

class Sieve {
public:
  vint spf;
  vector<bool> prime;

  Sieve(int n) {
    spf.assign(n + 1, 0);
    prime.assign(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i <= n; i++) {
      if (prime[i]) {
        spf[i] = i;
        for (int j = i * i; j <= n; j += i) {
          if (prime[j]) {
            prime[j] = false;
            spf[j] = i;
          }
        }
      }
    }
  }

  vector<pair<int, int>> factor(int x) {
    vector<pair<int, int>> res;
    while (x > 1) {
      int p = spf[x], cnt = 0;
      while (x % p == 0) {
        x /= p;
        cnt++;
      }
      res.push_back({ p, cnt });
    }
    return res;
  }
};

class DSU {
public:
  vint parent, size;

  DSU(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
};

class SegTree {
public:
  int n;
  vector<int> seg;

  int merge(int a, int b) {
    return a + b; // sum
  }

  int identity() { // initial value {sum: 0, min: inf, max: -inf, and: ~0ll, or: 0ll, xor: 0ll}
    return 0;
  }

  SegTree(vector<int>& a) {
    n = a.size();
    seg.assign(4 * n, identity());
    build(1, 0, n - 1, a);
  }

  void build(int idx, int l, int r, vector<int>& a) {
    if (l == r) {
      seg[idx] = a[l];
      return;
    }

    int mid = (l + r) / 2;

    build(2 * idx, l, mid, a);
    build(2 * idx + 1, mid + 1, r, a);

    seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
  }

  void update(int pos, int val) {
    update(1, 0, n - 1, pos, val);
  }

  void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
      seg[idx] = val;
      return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
      update(2 * idx, l, mid, pos, val);
    else
      update(2 * idx + 1, mid + 1, r, pos, val);

    seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
  }

  int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

  int query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return identity();

    if (ql <= l && r <= qr)
      return seg[idx];

    int mid = (l + r) / 2;

    return merge(
      query(2 * idx, l, mid, ql, qr),
      query(2 * idx + 1, mid + 1, r, ql, qr)
    );
  }
};
// SegTree st(a);
// st.update(pos, val);
// int ans = st.query(l, r);

// good for regular questions, unless there's insert/delete
class Fenwick {
public:
  int n;
  vint bit;

  Fenwick(int n) : n(n) {
    bit.assign(n + 1, 0);
  }

  Fenwick(int n, vint& a) : n(n) {
    bit.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
      update(i, a[i]);
  }

  // add val at index idx (0-based)
  void update(int idx, int val) {
    for (++idx; idx <= n; idx += idx & -idx)
      bit[idx] += val;
  }

  // prefix sum [0 ... idx]
  int query(int idx) {
    int res = 0;
    for (++idx; idx > 0; idx -= idx & -idx) // flips the last set bit (basically using 2s complement ki property)
      res += bit[idx];
    return res;
  }

  // range sum [l ... r]
  int query(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
  }
};

// Fenwick ft(n);
// Fenwick ft(n, a);
// ft.update(3, 5);
// ft.query(7);
// ft.query(2, 6);

void darelife() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i<n; i++) {
    cnt0 += (s[i] == '0');
    // cnt1 += (s[i] == '1');
  }
  int ans = cnt0;
  if (s[0] == '1') {
    cout << ans << endl;
    return;
  }
  for (int i=  0; i<n; i++) {
    cnt0 -= (s[i] == '0');
    cnt1 += (s[i] == '1');
    ans = min(ans, cnt0 + cnt1);
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  bool in = true;
  if (in) cin >> t;
  while (t--)
    darelife();
}

/*
 * ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS
 * remove fastio in interactive bruhh
 * Common methods to solve:
 * think in this order if nothing clicks:
 * 1) DP/GREEDY
 * 2) Bruteforce/optimised brutforce **IMP** (including reverse traversal)
 * 3) Precompute
 * 4) Binary Search
 * 5) Graphs - DFS/BFS
 * 6) 2 pointers / Sliding Window
 * 7) Deque + simulation instead of 2 pointers
 * 8) Maps
 * 9) Freq - Maps / Arrays
 * 10) Solution in reverse traversal
 * 11) PLOT GRAPHS : increasing/dec seq or math que
 * 12) div 2c + div 3d + div 4e usually bruteforce+imple
 * 13) div 2c + div 3e + div 4f usually algorithmic
 *
 * Debugging :
 * 1) Check for boundary conditions of input
 * 2) Test for random values  + write bruteforce
 * 3) Min/Max - initialise by 1e18
 * 4) Dont be stuck too long on the same approach think differently
 *

 * GRAPH ALGORITHMS:
 * 1) Topological Sort:
 *    - Kahn’s Algorithm (BFS) → O(V + E)
 *    - DFS-Based → O(V + E)
 *
 * 2) Cycle Detection:
 *    - Kahn’s (BFS): Detects if topological sort is incomplete
 *    - DFS with coloring/recursion stack → O(V + E)
 *
 * 3) Shortest Path:
 *    - Dijkstra’s → O((V + E) log V) (PQ)
 *    - Bellman-Ford → O(V * E) (Handles negatives)
 *    - Floyd-Warshall → O(V³) (All-pairs)
 *    - DAG Shortest Path → TopoSort + Relaxation → O(V + E)

 * 4) Minimum Spanning Tree:
 *    - Prim’s (PQ) → O(E log V)
 *    - Kruskal’s (Union-Find) → O(E log E)

 * 5) Strongly Connected Components (SCC):
 *    - Kosaraju’s → O(V + E)
 *    - Tarjan’s → O(V + E) (Low-Link Values)

 * 6) Bridges & Articulation Points:
 *    - DFS-based → O(V + E)

 * 7) Bipartite Check:
 *    - BFS/DFS Coloring → O(V + E)

 * DP ON GRAPHS (DAG):
 * 1) Toposort the graph.
 * 2) Relax edges in topo order.
 * 3) Maintain a `dist[]` array.
 * 4) Update distances during relaxation.

 * COMMON GRAPH PROBLEMS:
 * - Shortest Path (Dijkstra / Bellman-Ford)
 * - Longest Path in DAG
 * - Cycle Detection (Directed/Undirected)
 * - Topological Sorting
 * - Minimum Spanning Tree (Prim/Kruskal)
 * - SCCs (Kosaraju/Tarjan)
 * - Bipartite Check (BFS/DFS)

 * DP TIPS:
 * 1) Identify Overlapping Subproblems
 * 2) Define State & Transition
 * 3) Memoization (Top-Down) or Tabulation (Bottom-Up)
 * 4) Handle Base Cases
 * 5) Space Optimization (If possible)
*/
