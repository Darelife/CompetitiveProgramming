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
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  // int onelen = 0, zerolen = 0;
  // int ans = n;
  // int started = 0;
  // for (int i = 0; i < n; i++) {
  //   if (!started && a[i] == 1) {
  //     started = 1;
  //     onelen = 1;
  //   }
  //   if (a[i] == 1 && zerolen > 0 && started) {
  //     ans -= min(zerolen, onelen);
  //     zerolen = 0;
  //     onelen = 1;
  //   } else if (a[i] == 1) {
  //     onelen++;
  //   } else {
  //     zerolen++;
  //   }
  // }
  // cout << ans << endl;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) ans++;
  }
  ans = max(ans, n - ans);
  for (int i = 0; i < n; i++) {
    int temp = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] == 0) temp++;
    } for (int j = i; j < n; j++) {
      if (a[j] == 1) temp++;
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}