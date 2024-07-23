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
  // int n, m, k;
  // cin >> n >> m >> k;
  // vector<char> a(n + 2);
  // int water = 0;
  // a[0] = 'L';
  // a[n + 1] = 'L';
  // for (int i = 1; i < n + 1; i++) {
  //   char c;
  //   cin >> c;
  //   a[i] = c;
  //   if (c == 'W') {
  //     water++;
  //   }
  // }
  // // if (water > k) {
  // //   cout << "NO" << endl;
  // //   return;
  // // }

  // int pos = 0;
  // while (pos < n + 2) {
  //   int startPos = pos;
  //   // debug(pos, a[pos]);
  //   if (a[pos] == 'L') {
  //     int crocFound = -1;
  //     int logFound = -1;
  //     int waterFound = -1;
  //     for (int i = pos + m; i > pos;i--) {
  //       if (a[i] == 'L') {
  //         logFound = i;
  //         continue;
  //       }
  //       if (a[i] == 'W') {
  //         waterFound = i;
  //       }
  //       if (a[i] == 'C') {
  //         if (i == pos + m) {
  //           int endPos = i;
  //           debug(startPos, endPos);
  //           cout << "NO" << endl;
  //           return;
  //         }
  //         crocFound = i;
  //       }
  //     }
  //     // debug(logFound);
  //     if (waterFound > crocFound && logFound == -1) {
  //       pos = waterFound;
  //     } else {
  //       if (logFound != -1) pos = logFound;
  //       else pos = pos + m;
  //     }

  //   } else if (a[pos] == 'W' && k > 0) {
  //     pos++;
  //     k--;
  //   } else if (a[pos] == 'W') {
  //     cout << "NO" << endl;
  //     return;
  //   } else if (a[pos] == 'C') {
  //     int endPos = pos;
  //     debug(startPos, endPos);
  //     cout << "NO" << endl;
  //     return;
  //   } else {
  //     debug(startPos, pos);
  //     cout << "YES" << endl;
  //     return;
  //   }
  //   int endPos = pos;
  //   if (pos >= n + 2) {
  //     cout << "YES" << endl;
  //     return;
  //   }
  //   debug(startPos, endPos);
  // }
  // cout << "YES" << endl;





  // int n, m, k;
  // cin >> n >> m >> k;
  // string s;
  // cin >> s;
  // n += 2;
  // s = "L" + s + "L";


  int n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  int j = m - 1;
  int water = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') {
      j = m - 1; continue;
    } else if (s[i] == 'W' && j <= 0) water++;
    else if (j <= 0) {
      cout << "NO" << endl;
      return;
    }
    j--;
  }

  if (water > k) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    debug(i);
    solve();
  }
}