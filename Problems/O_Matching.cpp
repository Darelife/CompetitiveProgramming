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

// Saving these here to show the path to the most optimized solution...
// from a 2d dp to a 1d dp

// int bitmask(int i, int& n, int mask, vector<vector<int>>& a, vector<vector<int>>& dp) {
//   if (i == 1) return 1;
//   if (dp[i][mask] != -1) return dp[i][mask];
//   int ways = 0;
//   for (int j = 0; j < n; j++) {
//     if (((1 << i) & mask == 0) && a[i][j]) {
//       ways += bitmask(i + 1, n, mask | (1 << j), a, dp);
//     }
//   }
//   return dp[i][mask] = ways;
// }

// int bitmask(int i, int mask, int n, vector<vector<int>>& a, vector<int>& dp) {
//   if (mask == (1 << n) - 1) return 1;
//   if (dp[mask] != -1) return dp[mask];

//   int ways = 0;
//   for (int j = 0; j < n; j++) {
//     if ((mask & (1 << j)) == 0 && a[i][j]) {
//       ways = (ways + bitmask(i + 1, mask | (1 << j), n, a, dp)) % MOD;
//     }
//   }
//   return dp[mask] = ways;
// }

int bitmask(int mask, int n, vector<vector<int>>& a, vector<int>& dp) {

  // if it's the last val, 11111...(n times) (in binary)
  // btw, all the 1's in the mask represent the women who have been picked (not being sexist here...chill!!!!!)
  if (mask == (1 << n) - 1) return 1; // only 1 way...all the girls have been picked
  // so like, we've done everything. The thing we have is the best. Also, we have to add something. 
  // If it's 0, "ways" for all it's parents in the recursive tree will all be 0;
  // if we've already calculated the value
  if (dp[mask] != -1) return dp[mask];


  // this basically get's the permutations (need to remember how it works, as it's 
  // pretty useful in bitmasking qs (involving permutations))
  int i = __builtin_popcount(mask); // no. of 1s
  // this is technically the index of the man who is currently being considered
  // for picking. This is because, in the bitmask, the ith bit represents the
  // woman who is currently being considered for picking for the ith man

  int ways = 0;
  for (int j = 0; j < n; j++) { //iterating through all the girls
    if ((mask & (1 << j)) == 0 && a[i][j]) {
      //if the girl hasn't been picked....the first condition in the if statement 
      // is a standard way to check if the ith value is set or not in bitmasking
      ways = (ways + bitmask(mask | (1 << j), n, a, dp)) % MOD;
      // select that girl as picked (and do recursion!!!)
      // add the value of it, and all it's decendancts to ways.
    }
  }
  return dp[mask] = ways;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  vector<int> dp(1 << n, -1);
  cout << bitmask(0, n, a, dp) << "\n";
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}