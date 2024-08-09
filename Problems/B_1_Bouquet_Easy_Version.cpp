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
  int n, m;
  cin >> n >> m;
  vint a(n);
  map<int, int> mp;
  forr(i, n) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(allEle(a));
  int maxxsecond = 0;
  vector<pii> b;
  for (auto x : mp) {
    b.pba({ x.first, x.second });
    maxxsecond = max(maxxsecond, x.second * x.first);
  }
  sort(allEle(b));
  int ans = 0;
  int tempAns = 0;
  int p1 = 0, p2 = 0;
  forr(i, a.size()) {
    tempAns += a[i];
    for (p2; (tempAns > m); p2++)tempAns -= a[p2];
    for (p2; a[p1] - a[p2] > 1; p2++)tempAns -= a[p2];
    p1++;
    ans = max(ans, tempAns);
  }
  cout << ans << endl;
  // int ans = 0;
  // forr(i, b.size() - 1) {
  //   if (b[i + 1].first - b[i].first == 1) {
  //     ans = max(ans, b[i].second * b[i].first + b[i + 1].second * b[i + 1].first);
  //     if (ans >= m) {
  //       cout << m << endl;
  //       return;
  //     }
  //   }
  // }
  // ans = min(ans, m);
  // ans = max(ans, maxxsecond);
  // cout << max(ans, maxxsecond) << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}