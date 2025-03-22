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
  vint a(n); vcin(a, n);
  int cnt0 = 0, first0 = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0) { cnt0++; first0 = i; }
  }
  int ans = 1;
  if (cnt0) ans = max(ans, n - cnt0 + 1);
  else ans = n;
  vint mex(n + 1, 0);
  map<int, int> mp;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != mex[i + 1]) mex[i] = mex[i + 1];
    else {
      int j = a[i] + 1;
      while (mp[j]) j++;
      mex[i] = j;
    }
    mp[a[i]]++;
  }
  vint mini(n + 1, LONG_LONG_MAX);
  mini[0] = a[0];
  for (int i = 1; i < n; i++) {
    mini[i] = min(a[i], mini[i - 1]);
  }
  if (first0 >= 0) {
    for (int i = first0 - 1; i >= 0; i--) {
      if (mini[i] < mex[i + 1]) {
        ans = n - cnt0;
      }
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}
