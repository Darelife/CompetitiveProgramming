#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define f(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint)                                                             \
  for (auto x : vint)                                                          \
    cout << x << " ";                                                          \
  cout << endl;
#define vpstr(vstr)                                                            \
  for (auto x : vstr)                                                          \
    cout << x << " ";                                                          \
  cout << endl;

void __print(int x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
typedef tree<int, null_type, less<int>, rb_tree_tag,
  tree_order_statistics_node_update>
  pbds;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;


int power(int x, int y)
{
  int p = MOD;
  // Initialize answer
  int res = 1;

  // Check till the number becomes zero
  while (y > 0) {

    // If y is odd, multiply x with result
    if (y % 2 == 1)
      res = (res * x);

    // y = y/2
    y = y >> 1;

    // Change x to x^2
    x = (x * x);
  }
  return res % p;
}

int rec(int length, int count, int final_length, int final_count) {
  if (length + 1 == final_length) {
    if (count == final_count) {
      return count;
    }
    if (count + 1 == final_count) {
      return 26 - count;
    }
    return 0;
  }
  int ans = count * rec(count, length + 1, final_length, final_count);
  ans += (26 - count) * rec(count + 1, length + 1, final_length, final_count);
  return ans;
}

void recTabulation(int n, int x) {
  vector<vector<int>> dp(n + 1, vector<int>(x + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      if (j > 0) {
        dp[i][j] = dp[i - 1][j - 1] * (26 - (j - 1));
      }
      dp[i][j] += dp[i - 1][j] * j;
      dp[i][j] %= MOD;
    }
  }
  cout << dp[n][x] << endl;
}


void solve() {
  int n, x;
  cin >> n >> x;
  recTabulation(n, x);
}


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}