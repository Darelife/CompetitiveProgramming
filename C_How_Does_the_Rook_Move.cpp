#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;

const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

int dp(int n, map<int, int> &memo) {
  if (n == 0 || n == 1)
    return 1;
  if (memo.find(n) != memo.end())
    return memo[n];
  // memo[n] =
  //     ((2 * (n - 1) * dp(n - 2, memo)) % MOD + dp(n - 1, memo) % MOD) % MOD;
  return memo[n] =
             ((2 * (n - 1) * dp(n - 2, memo)) % MOD + dp(n - 1, memo) % MOD) %
             MOD;
}

void solve() {
  int n, k;
  cin >> n >> k;
  forr(i, k) {
    int x, y;
    cin >> x >> y;
    if (x == y)
      n--;
    else
      n -= 2;
  }
  map<int, int> memo;
  cout << dp(n, memo) << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}