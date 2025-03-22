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


bool canReach(int x, const vint& a, int n, int k) {
  vint dp(n, MOD);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int diff = abs(a[j] - a[i]);
      int cost = (diff >= x) ? 0 : 1;
      if (dp[i] + cost < dp[j]) {
        dp[j] = dp[i] + cost;
      }
    }
  }
  return dp[n - 1] <= k;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vint a(n);
  vcin(a, n);
  int maxDiff = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      maxDiff = max(maxDiff, abs(a[j] - a[i]));
    }
  }

  int low = 0, high = maxDiff + 1;
  int ans = 0;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (canReach(mid, a, n, k)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}