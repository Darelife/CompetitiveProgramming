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



  // int maxxIndex = 0; // first occurence of it
  // int maxx = 0;
  // int minnIndex = 0; // last occurence of it
  // int minn = inf;
  // for (int i = 0; i < n; i++) {
  //   if (a[i] > maxx) {
  //     maxx = a[i];
  //     maxxIndex = i;
  //   }
  //   if (a[i] <= minn) {
  //     minn = a[i];
  //     minnIndex = i;
  //   }
  // }

  // int maxOps = n - maxxIndex;
  // int minOps = minnIndex + 1;

  // // int ans1 = maxOps * maxOps + (maxxIndex + 1) * (maxxIndex + 1);
  // // int ans2 = minOps * minOps + 
  // int ans1, ans2;

  // if (minnIndex > maxxIndex) {
  //   ans1 = maxOps * maxOps + (maxxIndex + 1) * (maxxIndex + 1);
  //   if (maxxIndex == 0) {
  //     ans1 -= 1;
  //   }
  //   if (maxOps == 1) {
  //     ans1 -= 1;
  //   }
  //   ans2 = minOps * minOps + (n - (minnIndex)) * (n - minnIndex);
  //   if (minnIndex == n - 1) {
  //     ans2 -= 1;
  //   }
  //   if (minOps == 1) {
  //     ans2 -= 1;
  //   }ī
  // } else {
  //   ans1 = maxOps * maxOps + (minOps) * (minOps);
  //   if (maxOps == 1) {
  //     ans1 -= 1;
  //   }
  //   if (minOps == 1) {
  //     ans1 -= 1;
  //   }
  //   ans2 = ans1;
  // }

  // if (maxxIndex == 0) {
  //   ans1 = min(n * n, ans1);
  // }
  // if (minnIndex == n - 1) {
  //   ans1 = min(n * n, ans1);
  // }
  // cout << min(ans1, ans2) << endl;
  // // debug(ans1, ans2);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}