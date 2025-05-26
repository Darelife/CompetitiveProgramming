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

bool sol(int maxb, int n, vector<int>& b, vector<tuple<int, int, int>>& e) {
  vector<vector<pair<int, int>>> g(n); 
  //*these are the ache edges, max battery cap se chote hone chaiye,
  //* and im gonna make cap as the max bat it reaches with at node i
  for (auto &[u, v, w] : e) {
    if (w <= maxb) {
      g[u].pba({v, w});
    }
  }

  vint cap(n, -1);
  cap[0] = min(b[0], maxb);

  for (int i = 0; i < n; i++) {
    if (cap[i] == -1) continue;
    for (auto &[v, w] : g[i]) {
      if (cap[i] >= w && min(maxb, cap[i] + b[v]) > cap[v]) {
          cap[v] = min(maxb, cap[i] + b[v]);
      }
    }
  }

  return cap[n - 1] >= 0;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> b[i];

  vector<tuple<int, int, int>> e;
  set<int> w;

  for (int i = 0; i < m; i++) {
    int s, t, we;
    cin >> s >> t >> we;
    s--; t--;
    e.emplace_back(s, t, we);
    w.insert(we);
  }

  vector<int> ww(w.begin(), w.end());


  //*BS on max battery cap
  int l = 0, r = ww.size() - 1, ans = -1;
  while (l <= r) {
    int mid = l + (r-l)/2;
    if (sol(ww[mid], n, b, e)) {
      ans = ww[mid];
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << endl;
}


int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}