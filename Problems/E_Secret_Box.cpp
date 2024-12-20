#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;


const int inf = 1e9 + 5;

void solve() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  int ans = 0;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      // z = k/(i*j)
      // if (k % ((x - i + 1) * (y - j + 1)) == 0 && k / ((x - i + 1) * (y - j + 1)) <= z) {
      //   ans = max(ans, i * j * (k / ((x - i + 1) * (y - j + 1))));
      // }
      if (k % (i * j) == 0 && k / (i * j) <= z) {
        ans = max(ans, (x - i + 1) * (y - j + 1) * (z - k / (i * j) + 1));
      }
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}