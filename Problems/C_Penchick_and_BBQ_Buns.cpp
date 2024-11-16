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
  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      cout << (i / 2) + 1 << " ";
      cout << (i / 2) + 1 << " ";
    }
    cout << endl;
    return;
  }
  // if (n < 100) {
  //   cout << -1 << endl;
  //   return;
  // }

  // for (int i = 0; i < 64; i++) {
  //   cout << (i / 2) + 1 << " ";
  //   cout << (i / 2) + 1 << " ";
  // }
  // cout << 1 << " ";
  // for (int i = 64; i < 100; i++) {

  // }

  // 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34
  // 1  2  3  4  5  6  7  8  9  1  2  3  4  5  6  7  8  9  10 10 11 11 12 12 13 13 2  3  4  5  6  7  8  9


  if (n < 27) {
    cout << -1 << endl;
    return;
  }

  cout << "1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 10 10 11 11 12 12 13 13 2 ";
  // // return;


  // if (n >= 28) {
  //   cout << " 3";
  // }
  // if (n >= 29) {
  //   cout << " 4";
  // }
  // if (n >= 30) {
  //   cout << " 5";
  // }
  // if (n >= 31) {
  //   cout << " 6";
  // }
  // if (n >= 32) {
  //   cout << " 7";
  // }
  // if (n >= 33) {
  //   cout << " 8";
  // }
  // if (n >= 34) {
  //   cout << " 9";
  // }

  // for (int i = 0; i < n - 34; i++) {
  //   cout << " " << (i / 2) + 1 + 13;
  // }

  // cout << endl;

  // till 26 -> none
  // 27 to 34 -> yes

  // 35 to 42 -> no


  for (int i = 0; i < n / 2 - 13; i++) {
    cout << i + 14 << " " << i + 14 << " ";
  }
  cout << endl;

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}