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
  vint a(n);
  vcin(a, n);

  // int ans = 0;
  // for (int i = 0; i < n - 1; i++) if (a[i] == a[i + 1]) ans++;

  // if (ans == 0) {
  //   cout << 0 << endl;
  //   return;
  // }

  // // for (int i = 0; i < n / 2; i++) {
  // //   swap(a[i], a[n - i - 1]);
  // //   int tans = 0;
  // //   for (int j = 0; j < n - 1; j++) {
  // //     if (a[j] == a[j + 1]) {
  // //       tans++;
  // //     }
  // //   }
  // //   ans = min(ans, tans);
  // //   swap(a[i], a[n - i - 1]);
  // // }
  // int ops = 0;
  // for (int i = 0; i < n / 2; i++) {
  //   // if (a[i] != a[n - i - 1]) {
  //   //   if ((i != 0 && a[i] == a[i - 1]) || (i != n - 1 && a[i] == a[i + 1])) {
  //   //     int curAns = (i != 0 && a[i] == a[i - 1]) + (i != n - 1 && a[i] == a[i + 1]) + (n - i - 1 != 0 && a[n - i - 1] == a[n - i - 2]) + (n - i - 1 != n - 1 && a[n - i - 1] == a[n - i]);
  //   //     swap(a[i], a[n - i - 1]);
  //   //     int newAns = (i != 0 && a[i] == a[i - 1]) + (i != n - 1 && a[i] == a[i + 1]) + (n - i - 1 != 0 && a[n - i - 1] == a[n - i - 2]) + (n - i - 1 != n - 1 && a[n - i - 1] == a[n - i]);
  //   //     if (newAns > curAns) swap(a[i], a[n - i - 1]);
  //   //     else { ans -= curAns - newAns; ops++; }
  //   //   }
  //   //   // if ((n - i - 1 != 0 && a[n - i - 1] == a[n - i - 2]) || (n - i - 1 != n - 1 && a[n - i - 1] == a[n - i])) {
  //   //   //   ans++;
  //   //   // }
  //   // }
  //   // lets try every swap, and check if it is beneficial

  //   int curAns = (i != 0 && a[i] == a[i - 1]) + (i != n - 1 && a[i] == a[i + 1]) + (n - i - 1 != 0 && a[n - i - 1] == a[n - i - 2]) + (n - i - 1 != n - 1 && a[n - i - 1] == a[n - i]);
  //   swap(a[i], a[n - i - 1]);
  //   int newAns = (i != 0 && a[i] == a[i - 1]) + (i != n - 1 && a[i] == a[i + 1]) + (n - i - 1 != 0 && a[n - i - 1] == a[n - i - 2]) + (n - i - 1 != n - 1 && a[n - i - 1] == a[n - i]);
  //   if (newAns >= curAns) swap(a[i], a[n - i - 1]);
  //   else { ans -= curAns - newAns; ops++; }
  //   debug(a, newAns, curAns);

  // int ansi = 0;
  // forr(i, n) if (a[i] == a[i + 1]) ansi++;

  // int ans = ansi;

  // forr(i, n) {
  //   if (i >= n - i - 1) break;
  //   int d = ansi;
  //   d -= (i > 0 && a[i] == a[i - 1]) + (i < n - 1 && a[i] == a[i + 1]) + (n - i - 1 > 0 && a[n - i - 1] == a[n - i - 1 - 1]) + (n - i - 1 < n - 1 && a[n - i - 1] == a[n - i - 1 + 1]);
  //   swap(a[i], a[n - i - 1]);
  //   d += (i > 0 && a[i] == a[i - 1]) + (i < n - 1 && a[i] == a[i + 1]) + (n - i - 1 > 0 && a[n - i - 1] == a[n - i - 1 - 1]) + (n - i - 1 < n - 1 && a[n - i - 1] == a[n - i - 1 + 1]);

  //   ans = min(ans, d);

  //   swap(a[i], a[n - i - 1]);
  // }

  // cout << ans << endl;
  // int aa[n + 1];
  // for (int i = 1; i <= n; i++) {
  //   aa[i] = a[i - 1];
  // }
  // for (int i = 2; i <= n / 2; i++) {
  //   if (aa[i] == aa[i - 1] || aa[n - i + 1] == aa[n - i + 2]) swap(aa[i], aa[n - i + 1]);
  // }
  // int ans = 0;
  // forr(i, n - 1) ans += (aa[i + 1] == aa[i + 2]);
  // cout << ans << endl;

  for (int i = 1; i < n / 2; i++) {
    if (a[i] == a[i - 1] || a[n - i - 1] == a[n - i]) {
      swap(a[i], a[n - i - 1]);
    }
  }
  int ans = 0;
  forr(i, n - 1) ans += (a[i] == a[i + 1]);
  cout << ans << endl;
}



signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}

