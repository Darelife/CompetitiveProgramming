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
template <typename T, typename V> void __print(const pair<T, V>& x) { cerr << '{';__print(x.first);cerr << ',';__print(x.second); cerr << '}'; }
template <typename T> void __print(const T& x) { int f = 0;cerr << '{';for (auto& i : x)cerr << (f++ ? "," : ""), __print(i);cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t);if (sizeof...(v)) cerr << ", ";_print(v...); }
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif


typedef vector<int> vint;
#define vcin(vint, n) f(i, 0, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;

#define endl '\n'
const int inf = 1e9 + 5;
// const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  // vint a(n);
  // vcin(a, n);
  if (n < 3) {
    cout << 0 << endl;
    return;
  }

  int MOD = 998244353;

  //* we need the number of [1,2,....(x number of 2s, x can be 0 too)....,3]'s, as the array only contains 1,2,3

  // vint pos1, pos2, pos3;
  // f(i, 0, n) {
  //   if (a[i] == 1) pos1.pba(i);
  //   else if (a[i] == 2) pos2.pba(i);
  //   else pos3.pba(i);
  // }

  // int ans = 0;
  vint dp(4, 0);
  dp[0] = 1;
  while (n--) {
    int t; cin >> t;
    // cout << t << endl;
    // debug(dp);
    dp[t] = (t == 2) ? ((dp[t] + dp[t]) % MOD + dp[t - 1]) % MOD : (dp[t] + dp[t - 1]) % MOD;;
  }
  // debug(n);
  cout << dp[3] << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}