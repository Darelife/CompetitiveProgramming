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
  vint a(n);
  vcin(a,n);

  int ans = n;

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          int x = a[i], y = a[j];
          if ((x + y) % 2) continue;

          int t= 0;
          for (int k = 0; k < n; ++k) {
              if (a[k] >= min(x, y) && a[k] <= max(x, y)) {
                  t++;
              }
          }

          int rem = n - t;
          ans = min(ans, rem);
      }
  }

  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}