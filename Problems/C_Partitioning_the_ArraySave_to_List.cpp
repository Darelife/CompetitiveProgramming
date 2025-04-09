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
  vcin(a, n);

  vint factors;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      factors.pba(i);
      if (i != n / i) factors.pba(n / i);
    }
  }

  int ans = 0;
  for (auto i : factors) {
    int gcdd = 0;
    for (int j = 0; j + i < n; j++) {
      gcdd = __gcd(gcdd, abs(a[i + j] - a[j]));
    }
    if (gcdd != 1) ans++;
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}