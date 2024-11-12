#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  dp[0][0] = 0;
  // dp[i][j] = min operations to convert a[0..i-1] to b[0..j-1]
  for (int i = 1; i <= n; i++) dp[i][0] = i;
  for (int i = 1; i <= m; i++) dp[0][i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
    }
  }
  cout << dp[n][m] << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}