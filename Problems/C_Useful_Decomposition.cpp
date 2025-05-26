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
  /* 
    now here's the thing, 
    we can't have more than 1 vertex 
    with more than 3 edges.
    This is because, if you think about it,
    since there can't be any cycles, if a vertex (with 3 edges)
    has 2 branches, (3rd edge is connected to trunk of the tree)
    ....and if there's another such edge, since the path will get divided
    they'll have to somehow circle back to connect, which isn't allowed.

    if there's 1 such vertex...with more than 2 edges, we'll make it the center
    of all the paths

    if there's no such vertex,
    then it's just a simple path
  */

  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i<n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    adj[a].pba(b);
    adj[b].pba(a);
  }

  int ver = -1;
  for (int i = 0; i<n; i++) {
    if (ver == -1 && adj[i].size() > 2) ver = i;
    else if (adj[i].size() > 2) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
  if (ver != -1) {
    cout << adj[ver].size() << endl;
    for (int i = 0; i<n; i++) {
      if (adj[i].size() == 1) {
        cout << ver+1 << " " << i+1 << endl;
      }
    }
  } else {
    cout << 1 << endl;
    // find the 2 leaf nodes
    for (int i = 0; i<n; i++) {
      if (adj[i].size() == 1) {
        cout << i+1 << " ";
      }
    }
    cout << endl;
  }

}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; 
  while (t--) solve();
}