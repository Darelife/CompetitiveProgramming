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
  int x, y, k;
  cin >> x >> y >> k;
  
  if (x == y) {
    cout << 0 << endl;
    return;
  }
  int n = 2*1e6+10;

  // vector<int> visited(n+1, 0);
  vector<int> dist(n+1, -1);
  queue<pair<int,int>> q;
  q.push({x, 0});
  dist[x] = 0;

  // visited[x] = true;
  
  while (!q.empty()) {
    auto [u, step] = q.front();
    q.pop();
    for (int i = 1; i <= k; i++) {
      int mul = u * i;
      if (mul >= n) break;

      if (mul == y) {
        cout << step + 1 << endl;
        return;
      }

      if (dist[mul] == -1) {
        dist[mul] = step + 1;
        q.push({mul, step + 1});
      }
    }

    for (int i = 1; i*i <= u; i++) {
      if (u % i == 0) {
        int div1 = u / i;
        int div2 = i;

        if (i <= k) {
          if (div1 == y) {
            cout << step + 1 << endl;
            return;
          }
          if (dist[div1] == -1) {
            dist[div1] = step + 1;
            q.push({div1, step + 1});
          }
        }

        if (div1 != div2 && div1 <= k) {
          if (div2 == y) {
            cout << step + 1 << endl;
            return;
          }
          if (dist[div2] == -1) {
            dist[div2] = step + 1;
            q.push({div2, step + 1});
          }
        }
      }
    }
  }

  cout << -1 << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}