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
  vector<int> a(n);
  vcin(a, n);

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  /*
    * dp[i][rem] = number of good subsequences from i to n-1
    * such that we'll need to add "rem" elements to make it good
  */

  // *base case : for the last element, if  rem == 0, it's 1, otherwise, it's 0
  dp[n][0] = 1;

  /*
    * Transition
    * if picked, dp[i][rem] = (rem==0)?(dp[i+1][a[i]]):(dp[i+1][rem-1])
    * else, dp[i][rem] = dp[i+1][rem]
  */

  int mod = 998244353;

  for (int i = n - 1; i >= 0; i--) {
    for (int rem = 0; rem <= n; rem++) {
      int ans = 0;
      // * Case 1: We skip the element
      ans += (dp[i + 1][rem]) % mod;

      if (rem == 0) {
        // * The condition they gave us
        // * a[i] > 0 && also, a[i] <= n for the other condition
        if (a[i] > 0 && a[i] <= n) ans = (ans + dp[i + 1][a[i]]) % mod;
      } else {
        ans = (ans + dp[i + 1][rem - 1]) % mod;
      }
      dp[i][rem] = ans;
    }
  }

  // * Subtracting 1 to remove the case where no element got selected
  cout << (dp[0][0] - 1 + mod) % mod << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}