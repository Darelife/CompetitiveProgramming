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

int ask(int a0, int a1, int a2, int a3) {
  cout << "? " << a0 << " " << a2 << endl;
  int c;
  cin >> c;
  if (c == 0) {
    cout << "? " << a1 << " " << a3 << endl;
    cin >> c;
    if (c == 1) return a1;
    return a3;
  } else if (c == 1) {
    cout << "? " << a0 << " " << a3 << endl;
    cin >> c;
    if (c == 1) return a0;
    return a3;
  } else if (c == 2) {
    cout << "? " << a1 << " " << a2 << endl;
    cin >> c;
    if (c == 1) return a1;
    return a2;
  }
  return -1; // Added to avoid compiler warning
}
void solve() {
  int n;
  cin >> n;
  vint a(1 << n);
  iota(a.begin(), a.end(), 1); // Initialize vector with values from 1 to 2^n

  while (a.size() > 2) {
    vint tempA;
    for (int i = 0; i < a.size(); i += 4) {
      int d = ask(a[i], a[i + 1], a[i + 2], a[i + 3]);
      tempA.pba(d);
    }
    a = move(tempA); // Use move to avoid copying
  }

  if (a.size() == 2) {
    cout << "? " << a[0] << " " << a[1] << endl;
    int c;
    cin >> c;
    // im just hoping that there's no tie in the finals
    if (c == 1) cout << "! " << a[0] << endl;
    else cout << "! " << a[1] << endl;
    return;
  }
  cout << "! " << a[0] << endl;

}


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}