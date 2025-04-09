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

  vector<int> dist(n, LLONG_MAX);
  vector<int> parent(n, -1);
  vector<vector<pair<int, int>>> adj(n);

  for (int i = 0; i < m; i++) {
    int x, y, z; cin >> x >> y >> z;
    x--; y--;
    adj[x].push_back({ y, z });
    adj[y].push_back({ x, z });
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({ 0, 0 });
  dist[0] = 0;

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;

    for (auto [v, w] : adj[u]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        parent[v] = u;
        pq.push({ dist[v], v });
      }
    }
  }

  if (dist[n - 1] == LLONG_MAX) {
    cout << "-1" << endl;
    return;
  }

  vector<int> path;
  for (int u = n - 1; u != -1; u = parent[u]) {
    path.push_back(u);
  }

  reverse(path.begin(), path.end());
  for (int i = 0; i < path.size(); i++) {
    cout << path[i] + 1 << " ";
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}