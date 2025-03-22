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

const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  int x = 0;
  for (int i = 0; i < n - 1; i++) {
    x = __gcd(x, abs(a[i + 1] - a[i]));
  }
  if (x < 1) x = 1;
  sort(a.begin(), a.end());

  int ans = 0, t = a[n - 1];
  for (int j = n - 1; j >= 0 && a[j] == t; j--) {
    t -= x;
    ans++;
  }
  int ans2 = 0;
  for (int i = 0; i < n; i++) {
    ans2 += abs(a[i] - a[n - 1] - x) / x;
    ans += abs(a[i] - a[n - 1]) / x;
  }
  cout << min(ans, ans2) << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}