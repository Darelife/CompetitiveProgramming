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
  int n, k;
  cin >> n >> k;
  vint p(n), d(n);
  vcin(p, n);
  vcin(d, n);

  int N = n * 2 * k;
  vector<vector<int>> radj(N);
  vector<bool> esc(N, false);
  queue<int> q;

  f(i, 0, n) f(r, 0, k) f(j, 0, 2) {
    int id = i * (2 * k) + j * k + r;
    int dir = (j == 0) ? 1 : -1;
    int effDir = (r == d[i]) ? -dir : dir;
    int t = i + effDir;

    if (t < 0 || t >= n) {
      if (!esc[id]) {
        esc[id] = 1;
        q.push(id);
      }
    } else {
      int newRem = (r + abs(p[t] - p[i])) % k;
      int newDir = (effDir == 1) ? 0 : 1;
      radj[t * (2 * k) + newDir * k + newRem].pba(id);
    }
  }


  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : radj[u]) {
      if (!esc[v]) {
        esc[v] = true;
        q.push(v);
      }
    }
  }

  int qq;
  cin >> qq;
  while (qq--) {
    int s; cin >> s;
    int i = lower_bound(p.begin(), p.end(), s) - p.begin();
    if (i == n) { cout << "YES" << endl; continue; }
    int r = (p[i] - s) % k;
    int id = i * (2 * k) + r;
    cout << (esc[id] ? "YES" : "NO") << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}