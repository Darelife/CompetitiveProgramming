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

void Dfs(int node, vector<set<int>>& adj, set<int>& currComp, vector<bool>& vis) {
  if (vis[node])
    return;

  vis[node] = true;
  currComp.insert(node);
  for (int v : adj[node]) {
    Dfs(v, adj, currComp, vis);
  }
}

vector<set<int>> GetComponents(vector<set<int>>& adj, int n) {
  vector<set<int>> comps;
  vector<bool> vis(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      set<int> currComp;
      Dfs(i, adj, currComp, vis);
      comps.push_back(currComp);
    }
  }
  return comps;
}

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<set<int>> fGraph(n + 1), gGraph(n + 1);
  int u, v;

  for (int i = 0; i < m1; i++) {
    cin >> u >> v;
    fGraph[u].insert(v);
    fGraph[v].insert(u);
  }

  for (int i = 0; i < m2; i++) {
    cin >> u >> v;
    gGraph[u].insert(v);
    gGraph[v].insert(u);
  }

  int addEdgeCount = 0, removeEdgeCount = 0;
  vector<set<int>> gComps = GetComponents(gGraph, n);

  vector<int> gCompOfNode(n + 1, -1), fCompOfNode(n + 1, -1);

  for (int i = 0; i < gComps.size(); i++) {
    for (int node : gComps[i]) {
      gCompOfNode[node] = i;
    }
  }

  vector<pair<int, int>> edgesToRemove;

  for (int u = 1; u <= n; u++) {
    for (int v : fGraph[u]) {
      if (v > u && gCompOfNode[v] != gCompOfNode[u]) {
        removeEdgeCount++;
        edgesToRemove.push_back({ u, v });
      }
    }
  }

  for (auto [u, v] : edgesToRemove) {
    fGraph[u].erase(v);
    fGraph[v].erase(u);
  }

  vector<set<int>> fComps = GetComponents(fGraph, n);

  for (int i = 0; i < fComps.size(); i++) {
    for (int node : fComps[i]) {
      fCompOfNode[node] = i;
    }
  }
  addEdgeCount = fComps.size() - gComps.size();
  cout << addEdgeCount + removeEdgeCount << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}
