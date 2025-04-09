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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u - 1].push_back({ v - 1, w });
    adj[v - 1].push_back({ u - 1, w });
  }
  vint b(n);
  vcin(b, n);

  vector<vector<int>> dist(n, vector<int>(n, LLONG_MAX));

  dist[0][0] = 0;

  priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
  > pq;

  // time, node, bike
  pq.push({ 0, {0, 0} });

  while (!pq.empty()) {
    auto [t, p] = pq.top();
    auto [u, b1] = p;
    pq.pop();

    if (t > dist[u][b1]) continue;

    for (auto it : adj[u]) {
      auto [v, w] = it;
      int t1 = dist[u][b1] + b[b1] * w;
      if (b[v] < b[b1]) {
        if (t1 < dist[v][v]) {
          dist[v][v] = t1;
          pq.push({ t1, {v, v} });
        }
      } else {
        if (t1 < dist[v][b1]) {
          dist[v][b1] = t1;
          pq.push({ t1, {v, b1} });
        }
      }
    }
  }

  int ans = *min_element(dist[n - 1].begin(), dist[n - 1].end());
  if (ans == LLONG_MAX) ans = -1;
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}