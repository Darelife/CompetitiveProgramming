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
void __print(long double x) { cerr << setprecision(7) << fixed << x; }
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

int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int anss(int rx, int ry) {
  if (rx > ry) {
    return ((ry + 1) * ry) / 2 + (rx - (ry + 1)) * ry;
  }
  return rx * (rx - 1) / 2;
}

vector<string> splitString(const string& str, char delimiter) {
  vector<string> tokens;
  stringstream ss(str);
  string token;

  while (getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

string to_string_with_precision(long double value, int precision) {
  ostringstream out;
  out << fixed << setprecision(precision) << value;
  return out.str();
}

void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  long double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      // ans += max((long double)0, (long double)(a[i] - a[j]) / a[i]);
      int t = min(a[i], a[j]);
      int c = t * (t - 1) / 2;
      if (a[j] > a[i]) {
        c += (a[j] - a[i]) * a[i];
      }
      ans += (double)c / (a[j] * a[i]);
    }
  }
  // Round to 6 decimal places using bankers' rounding


  // cout << setprecision(8) << fixed;
  // cout << ans << endl;

  // Round to 6 decimal places using bankers' rounding
  ans = round(ans * 100000000) / 100000000;

  // Truncate to 6 decimal places
  cout << setprecision(6) << fixed;
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}
