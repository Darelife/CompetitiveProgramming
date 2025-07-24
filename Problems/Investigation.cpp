#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a)                                                              \
  cout << #a << " = ";                                                         \
  for (auto x : a)                                                             \
    cout << x << " ";                                                          \
  cout << "\n";

#define f(i, a, b) for (int i = a; i < b; i++)
#define pba push_back

typedef vector<int> vint;
#define vcin(vint, n) f(i, 0, n) cin >> vint[i]
#define vpin(vint)                                                             \
  for (auto x : vint)                                                          \
    cout << x << " ";                                                          \
  cout << endl;

#define endl '\n'
const int inf = 1e18;
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
template <typename T, typename V> void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
typedef tree<int, null_type, less<int>, rb_tree_tag,
  tree_order_statistics_node_update>
  pbds;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

#define v vector
v<v<pair<int, int>>> adj;
vector<int> dist, ways, minn, maxx, vis;

void dijkstra(int u) {
  priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<>
  > pq;
  dist[u] = 0;
  minn[u] = 0;
  maxx[u] = 0;

  // dist, u
  pq.push({ 0, u });
  ways[u] = 1;
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    // if (vis[u]) continue;
    // vis[u] = 1;
    if (d > dist[u]) continue;
    for (auto [v, dd] : adj[u]) {
      int t = dd + dist[u];
      if (t == dist[v]) {
        ways[v] = (ways[v] + ways[u]) % MOD;
        minn[v] = min(minn[v], minn[u] + 1);
        maxx[v] = max(maxx[v], maxx[u] + 1);
      } else if (t < dist[v]) {
        ways[v] = ways[u];
        minn[v] = minn[u] + 1;
        maxx[v] = maxx[u] + 1;
        dist[v] = t;
        pq.push({ t, v });
      }
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  dist.resize(n, inf);
  ways.resize(n);
  minn.resize(n, inf);
  maxx.resize(n);
  vis.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    adj[a].pba({ b,c });
    // adj[b].pba({ a,c });
  }
  dijkstra(0);
  cout << dist[n - 1] << " " << ways[n - 1] << " " <<
    minn[n - 1] << " " << maxx[n - 1] << endl;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}