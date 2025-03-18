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
  int n, m, l;
  cin >> n >> m >> l;
  vector<pair<int, int>> h(n);
  f(i, 0, n) {
    cin >> h[i].first;
    int x;
    cin >> x;
    h[i].second = x - h[i].first + 1;
  }
  int ans = 0;
  vector<pair<int, int>> p(m);
  for (int i = 0; i < m; i++)
    cin >> p[i].first >> p[i].second;
  priority_queue<int> pq;
  int pindex = 0;
  int jump = 1;
  for (int i = 0; i < n; i++) {
    // cout << "index : " << h[i].first << endl;
    while (p[pindex].first < h[i].first && pindex < m) pq.push(p[pindex++].second);
    while (jump <= h[i].second) {
      if (pq.empty()) {
        cout << -1 << endl;
        return;
      }
      ans++;
      jump += pq.top();
      // cout << pq.top() << endl;
      pq.pop();
    }
  }
  cout << ans << endl;

}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}