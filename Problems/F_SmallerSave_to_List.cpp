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
  bool t = false, s = false;
  int tt = 0, ss = 0;
  while (n--) {
    int a, k;
    string x;
    cin >> a >> k >> x;
    for (auto i : x) {
      if (a == 2) {
        if (i != 'a')
          t = 1;
        else tt += k;
      } else {
        if (i != 'a')
          s = 1;
        else ss += k;
      }

    } if (t) {
      cout << "YES" << endl;
    } else if (!s and tt > ss)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}