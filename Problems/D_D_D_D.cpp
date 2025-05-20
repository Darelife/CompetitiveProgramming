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
const int inf = 1e18;
const int MOD = 1e9 + 7;

void solve() {
  int n, m, l;
  cin >> n >> m >> l;
  vint a(l);
  vcin(a, l);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    adj[x].pba(y);
    adj[y].pba(x);
  }


  int sum = accumulate(a.begin(), a.end(), 0);
  int sodd = LLONG_MAX;
  for (int i = 0; i < l; i++) {
    sodd = (a[i] % 2 ? min(sodd, a[i]) : sodd);
  }

  vector<vector<int>> dist(n, vector<int>(2, inf));
  dist[0][0] = 0;

  // node, odd/even
  queue<pair<int, int>>q;
  q.push({ 0,0 });

  while (!q.empty()) {
    auto [u, o] = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (o == 0) {
        if (dist[v][1] > dist[u][0] + 1) {
          dist[v][1] = dist[u][0] + 1;
          q.push({ v, 1 });
        }
      } else {
        if (dist[v][0] > dist[u][1] + 1) {
          dist[v][0] = dist[u][1] + 1;
          q.push({ v, 0 });
        }
      }
    }
  }

  string ans = "";

  int sumEven = (sum % 2 == 0) ? sum : sum - sodd;
  int sumOdd = (sum % 2 == 1) ? sum : sum - sodd;

  for (int i = 0; i < n; i++) {
    if (dist[i][0] <= sumEven) {
      ans += "1";
    } else if (dist[i][1] <= sumOdd) {
      ans += "1";
    } else {
      ans += "0";
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}