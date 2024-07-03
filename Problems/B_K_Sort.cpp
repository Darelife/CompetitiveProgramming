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
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  // k <= n -> pay k+1
  // choose k indexes...increase the value of those indexes by 1
  // non-decreasing
  vint diff;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] < a[i])
      diff.pba(-a[i + 1] + a[i]);
  }
  diff.clear();
  int maxx = a[0];
  for (int i = 0; i < n; i++) {
    maxx = max(maxx, a[i]);
    if (maxx > a[i])
      diff.pba(maxx - a[i]);
  }
  sort(allEle(diff));
  // map<int, int> mp;
  // for (int i = 0; i < diff.size(); i++)
  //   mp[diff[i]]++;
  debug(diff);
  // int ans = 0;
  if (diff.size() == 0) {
    cout << 0 << endl;
    return;
  }
  int ans = diff[diff.size() - 1];
  int sub = 0;
  forr(i, diff.size()) {
    ans += (diff[i] - sub) * (diff.size() - i);
    sub = diff[i];
  }
  // int ans = 0;
  // int sub = 0;
  // for (int i = 0; i < diff.size(); i++) {
  //   ans += (diff[i] - sub) * (diff.size() - i + 1);
  //   sub += diff[i];
  //   debug(ans, sub);
  // }
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