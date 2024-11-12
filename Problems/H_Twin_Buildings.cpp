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

void solve() {
  int n;
  cin >> n;
  vector<pii> a(n);
  int ans = 0;
  forr(i, n) {
    int x, y;
    cin >> x >> y;
    a[i] = { min(x,y), max(x,y) };
    ans = max(ans, x * y);
  }

  // double ans2 = 0;
  // for (int i = 0; i < n; i++) {
  //   int x = a[i].first;
  //   int y = a[i].second;
  //   double val = (double)x * y;
  //   if (val > ans) {
  //     ans2 = ans;
  //     ans = val;
  //   } else if (val > ans2) {
  //     ans2 = val;
  //   }
  // }
  // ans2 /= 2;
  // ans /= 2;
  // set precision to 1 decimal place
  // cout << fixed << setprecision(1);
  // cout << max(ans, ans2) << endl;

  // vector<vector<pair<double, double>>> v(10000, vector<pair<double, double>>(10000, { 0, 0 }));
  // // base case -> 0,0 -> {0,0}
  // v[0][0] = { 0, 0 };
  // for (int i = 1; i <= 10000; i++) {
  // }
  // sort(a.begin(), a.end(), greater<pair<int, int>>());
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int SecondMaxLargeSide = 0;
  // now, a is sorted in descending order....and basically, if the smallest side of 2 values are equal, then, the first value will have the largest area (as it will have the largest value of the larger side)
  for (int i = 0; i < n; i++) {
    int x = a[i].first;
    int y = a[i].second;
    ans = max(ans, 2 * x * min(y, SecondMaxLargeSide));
    // basically, if y>SecondMaxLargeSide....i'll ensure that I choose secondMaxLargeSide as I need the box to fit into the largest box
    SecondMaxLargeSide = max(SecondMaxLargeSide, y);
  }
  // cout << fixed << setprecision(1) << (double)ans / 2 << endl;
  if (ans % 2 == 0) {
    cout << ans / 2 << ".0" << endl;
  } else {
    cout << ans / 2 << ".5" << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}