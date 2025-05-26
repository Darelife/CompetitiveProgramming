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
  int n;
  cin >> n;
  vint d(n);
  vcin(d, n);
  vector<pair<int, int>> o(n);
  f(i, 0, n) cin >> o[i].first >> o[i].second;

  vector<pair<int, int>> ran(n + 1);
  ran[0] = {0, 0};

  f(i, 1, n + 1) {
    int prevl = ran[i - 1].first, prevr = ran[i - 1].second;
    int minn, maxx;
    if (d[i - 1] == 0) {
      minn = prevl;
      maxx = prevr;
    } else if (d[i - 1] == 1) {
      minn = prevl + 1;
      maxx = prevr + 1;
    } else {
      minn = prevl;
      maxx = prevr + 1;
    }
    if (max(minn, o[i - 1].first) > min(maxx, o[i - 1].second)) {
      cout << -1 << endl;
      return;
    }
    ran[i] = {max(minn, o[i - 1].first), min(maxx, o[i - 1].second)};
  }
  // *basically abhi tak we've calculated the range of the vals till this point

  vint ans(n);
  int h = ran[n].first; // *min value
  for (int i = n; i >= 1; i--) {
    int l = ran[i - 1].first, r = ran[i - 1].second;
    if (d[i - 1] != -1) {
      ans[i - 1] = d[i - 1];
      h -= d[i - 1];
    } else {
      int h1 = h - 1;
      if (h1 >= l && h1 <= r) {
        ans[i - 1] = 1;
        h = h1;
      } else {
        ans[i - 1] = 0;
      }
    }
  }
  vpin(ans);
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}