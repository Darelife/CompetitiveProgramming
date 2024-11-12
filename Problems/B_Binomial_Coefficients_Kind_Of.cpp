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

int MOD = 1e9 + 7;

int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % MOD;
    a = a * a;
    b >>= 1;
  }
  return res;
}


/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long x, unsigned int y, int p)
{
  int res = 1;     // Initialize result 

  x = x % p; // Update x if it is more than or 
  // equal to p

  if (x == 0) return 0; // In case x is divisible by p;

  while (y > 0)
  {
    // If y is odd, multiply x with result 
    if (y & 1)
      res = (res * x) % p;

    // y must be even now 
    y = y >> 1; // y = y/2 
    x = (x * x) % p;
  }
  return res;
}

void solve(const vector<vector<int>>& C) {
  int t;
  cin >> t;
  vector<int> n(t), k(t);
  for (int i = 0; i < t; ++i) {
    cin >> n[i];
  }
  for (int i = 0; i < t; ++i) {
    cin >> k[i];
  }

  for (int i = 0; i < t; ++i) {
    cout << C[n[i]][k[i]] << endl;
  }
}


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  vint n(t), k(t);
  vcin(n, t); vcin(k, t);
  // int N = *max_element(allEle(n));

  // vector<vector<int>> C = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

  // for (int i = 0; i <= N; i++) {
  //   C[i][0] = 1;
  //   C[i][i] = 1;
  //   if (i == 0) continue;
  //   for (int j = 1; j < i; j++) {
  //     C[i][j] = (C[i][j - 1] + C[i - 1][j - 1]) % MOD;
  //   }
  // }
  // for (int i = 0; i < t; i++) {
  //   cout << C[n[i]][k[i]] << endl;
  // }
  for (int i = 0; i < t; i++) {
    cout << power(2, k[i], 1e9 + 7) << endl;
  }
}
