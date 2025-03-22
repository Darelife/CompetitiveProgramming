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

int ciel(int a, int b) {
  return (a + b - 1) / b;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vint h(n);
  vcin(h, n);
  vint a(n);
  vcin(a, n);

  int l = 0, r = 1e18;
  while (l + 1 < r) {
    int mid = l + (r - l) / 2;
    map<int, int> prefixMap;
    for (int i = 0; i < n; i++) {
      if (m >= ciel(h[i], mid)) {
        int distance = m - ciel(h[i], mid);
        if (distance < 0) continue;
        // ab vo prefix waali cheez
        // pos - distance pe 1, and pos + distance + 1 pe -1 -> baadme prefix sum me, sab kuch sahi ho jaayega
        prefixMap[a[i] - distance]++;
        prefixMap[a[i] + distance + 1]--;
      }
    }
    vint prefixVec;
    int maxi = 0;
    for (auto i : prefixMap) {
      prefixVec.pba(i.second + (prefixVec.empty() ? 0 : prefixVec.back()));
      maxi = max(maxi, prefixVec.back());
    }
    if (maxi >= k) r = mid;
    else l = mid;
  }
  cout << (r == 1e18 ? -1 : r) << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}