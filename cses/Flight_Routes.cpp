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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u - 1].push_back({ v - 1, w });
  }

  // cost, node
  priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
  > pq;

  // for each node, a pq to get the best k
  vector<priority_queue<int>> best(n);

  pq.push({ 0, 0 });

  best[0].push(0);

  while (!pq.empty()) {
    auto [cost, node] = pq.top();
    pq.pop();

    if (cost > best[node].top()) continue;

    for (auto it : adj[node]) {
      if (best[it.first].size() < k) {
        best[it.first].push(cost + it.second);
        pq.push({ cost + it.second, it.first });
      } else if (best[it.first].top() > cost + it.second) {
        best[it.first].pop();
        best[it.first].push({ cost + it.second });
        pq.push({ cost + it.second, it.first });
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < k; i++) {
    ans.push_back(best[n - 1].top());
    best[n - 1].pop();
  }
  for (int i = k - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  cout << endl;

}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}