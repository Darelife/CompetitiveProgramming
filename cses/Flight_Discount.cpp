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
  // note to self: watched a solution vid...solve again
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u - 1].push_back({ v - 1, w });
  }
  vector<vector<int>> dist(n, vector<int>(2, LLONG_MAX));
  dist[0][0] = 0; // we've not used the discount yet
  dist[0][1] = 0; // we've used the discount

  // cost, node, flag (if we've used the discount or not)
  priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
  > pq;

  pq.push({ 0, { 0, 0 } });

  while (!pq.empty()) {
    auto [d, p] = pq.top();
    auto [u, f] = p;
    pq.pop();

    // if we have already found a better path to u
    if ((f == 1 && (dist[u][1] < d)) || (f == 0 && dist[u][0] < d)) continue;

    for (auto e : adj[u]) {
      auto [v, w] = e;
      if (f == 0) {
        // we aren't using the discount rn
        if (dist[v][0] > d + w) {
          dist[v][0] = d + w;
          pq.push({ dist[v][0], {v, 0} });
        }
        // lets use the discount now
        if (dist[v][1] > d + w / 2) {
          dist[v][1] = d + w / 2;
          pq.push({ dist[v][1], {v, 1} });
        }
      } else {
        if (dist[v][1] > d + w) {
          // we have already used the discount in the past
          dist[v][1] = d + w;
          pq.push({ dist[v][1], {v, 1} });
        }
      }
    }
  }
  cout << dist[n - 1][1] << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}