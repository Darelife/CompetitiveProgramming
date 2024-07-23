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

void solve() {
  // cout << "---------------" << endl;
  int n, m;
  cin >> n >> m;
  vector<vint> a(n, vint(m));
  vector<vint> b(n, vint(m));
  char c;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c;
      a[i][j] = c - '0';
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c;
      b[i][j] = c - '0';
    }
  }
  // int n, m;
  // cin >> n >> m;
  // vector<vint> a(n, vint(m));
  // vector<vint> b(n, vint(m));
  // forr(i, n) {
  //   // vcin(a[i], m);
  //   // FUCKKKKKKK
  //   char c;
  //   for (int j = 0; j < m; j++) {
  //     cin >> c;
  //     a[i][j] = c - '0';
  //   }
  // }
  // forr(i, n) {
  //   // vcin(b[i], m);
  //   char c;
  //   for (int j = 0; j < n; j++) {
  //     cin >> c;
  //     a[i][j] = c - '0';
  //   }
  // }
  int diff = 0;
  // debug(diff);
  for (int i = n - 1; i > 0; i--) {
    // for (int j = m - 1; m > 0; j--) {
    for (int j = m - 1; j > 0; j--) {
      if (a[i][j] == b[i][j]) continue;
      else {
        int x = a[i][j], y = b[i][j];
        diff = 3 + y - x;
        // if (diff < 0) diff += 3;
        diff %= 3;
        a[i][j] = b[i][j];
        a[i - 1][j] = (a[i - 1][j] + 2 * diff) % 3;
        a[i][j - 1] = (a[i][j - 1] + 2 * diff) % 3;
        a[i - 1][j - 1] = (a[i - 1][j - 1] + diff) % 3;
        // diff = 0;
      }
    }
  }
  debug(diff);

  for (int i = 0; i < n; ++i) {
    if (a[i][0] != b[i][0]) {
      cout << "NO" << endl;
      return;
    }
  }
  for (int j = 0; j < m; ++j) {
    if (a[0][j] != b[0][j]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  // forr(i, n) {
  //   if (a[i][0] != b[i][0]) {
  //     cout << "NO" << endl;
  //     return;
  //   }
  // }
  // forr(i, m) {
  //   if (a[0][i] != b[0][i]) {
  //     cout << "NO" << endl;
  //     return;
  //   }
  // }
  // cout << "YES" << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}