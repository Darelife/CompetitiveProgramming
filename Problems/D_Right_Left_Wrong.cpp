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
  string s;
  cin >> s;
  int ans = 0;
  int tempSum = 0;
  int started = 0;

  // string ss = "";
  // forr(i, n) {
  //   if (s[i] == 'R') {
  //     ss += s[i];
  //     if (i > 0) {
  //       if (s[i - 1] == 'R') {
  //         ss[i - 1] = '.';
  //       }
  //     }
  //   } else {
  //     ss += s[i];
  //   }
  // }
  // debug(s, ss);
  // s = ss;

  // instead of tempSum and all, we can just use prefix sum
  vint p(n + 1, 0);
  forr(i, n) {
    p[i + 1] = p[i] + a[i];
  }

  // forr(i, n) {
  //   if (!started) {
  //     if (s[i] == 'L') {
  //       started = 1;
  //     }
  //   }
  //   tempSum += a[i];
  //   if (s[i] == 'R' && started) {
  //     started = 0;
  //     ans += tempSum;
  //     tempSum = 0;
  //   }
  // }
  // cout << ans << endl;

  // NOTE TO FUTURE SELF.....I've given up

  // we can use like, 2 pointers instead of the basic thing
  int p1 = 0, p2 = n - 1;
  while (p1 < p2) {
    if (s[p1] == 'L' && s[p2] == 'R') {
      ans += p[p2 + 1] - p[p1];
      p1++;
      p2--;
    }
    if (s[p1] == 'R') {
      p1++;
    }
    // else p2++;
    else if (s[p2] == 'L') {
      p2--;
    }

  }
  cout << ans << endl;

  //! I DON'T GET WHAT'S WRONG!!!!
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}