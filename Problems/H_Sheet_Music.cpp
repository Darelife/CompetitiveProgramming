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
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;

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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const int inf = 1e9 + 5;
int mod = 998244353;

int binpow(int a, int b) {
  if (b == 0) return 1;
  if (b % 2) return a * binpow(a, b - 1) % mod;
  int res = binpow(a, b / 2);
  return res * res % mod;
}
const int N = 1e7 + 1;
int ifact[N], fact[N], dp[N], ans[N];
// const int mod = 1e9 + 7;

void solve() {
  dp[0] = 1;
  for (int i = 1;i < N;i++) {
    dp[i] = 2 * dp[i - 1] % mod;
  }
  fact[0] = 1;
  for (int i = 1;i < N;i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  ifact[N - 1] = binpow(fact[N - 1], mod - 2);
  for (int i = N - 2;i >= 0;i--) {
    ifact[i] = ifact[i + 1] * (i + 1) % mod;
  }


  int n, k;
  cin >> n >> k;
  n--;
  k--;
  ans[0] = 1;
  int tmp = 0;
  if (k == 0) {
    tmp = 2;
  }
  for (int i = 1;i <= n;i++) {
    ans[i] = (dp[i] - tmp + mod) % mod;
    tmp = 2 * tmp % mod;
    if (i > k) {
      tmp = (tmp + ans[i + 1 - (k + 1)]) % mod;
    }
    if (i == k) {
      tmp = 2;
    }
  }
  int res = 0;
  for (int i = 0;i <= n;i++) {
    int comb = fact[n] * ifact[n - i] % mod * ifact[i] % mod;
    res = (res + ans[n - i] * comb % mod) % mod;
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}