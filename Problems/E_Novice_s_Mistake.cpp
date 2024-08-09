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
  int count = 0;
  if (n == 1) {
    cout << 9999 << endl;
    for (int i = 1; i <= 9999; i++) {
      cout << i + 1 << " " << i << endl;
    }
    return;
  }
  string nn = "";
  for (int i = 0; i < 6; i += to_string(n).size()) {
    nn += to_string(n);
  }
  vector<pii> ans;
  for (int i = 1; i < 6; i++) {
    string a = nn.substr(0, i);
    int aa = stoll(a);
    // n*x - y = aa
    // n.size()*x - y = a.size()

    // n*x - n.size()*x+a.size() = aa
    // x = (aa-n.size())/(n-a.size())
    if ((aa - a.size()) % (n - to_string(n).size()) == 0) {
      debug(aa);
      int x = (aa - a.size()) / (n - to_string(n).size());
      int y = n * x - aa;
      if (y >= 0 && x != 0 && y != 0 && x <= 10000 && y <= 10000) {
        ans.pba({ x, y });
      }
    }
  }
  cout << ans.size() << endl;

  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}