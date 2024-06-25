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


const int inf = 1e9 + 5;

// void solve() {
//   int n;
//   cin >> n;
//   vint a(n);
//   vcin(a, n);
//   vint b(n);
//   vcin(b, n);
//   int m;
//   cin >> m;
//   // vint c(m);
//   // vcin(c, m);

//   map<int, int> backupB;
//   map<int, int> diff;
//   for (int i = 0; i < n; i++) {
//     if (a[i] != b[i]) {
//       diff[b[i]]++;
//       backupB[b[i]] = 1;
//     }
//   }
//   for (int i = 0; i < m; i++) {
//     int c;
//     cin >> c;
//     if (diff.find(c) != diff.end()) {
//       diff[c]--;
//       if (diff[c] == 0) {
//         diff.erase(c);
//       }
//       if (i == m - 1 && diff.empty()) {
//         cout << "YES" << endl;
//         return;
//       } else {
//         cout << "NO" << endl;
//         return;
//       }
//     } else if (backupB.find(c) != backupB.end()) {
//       if (i == m - 1 && diff.empty()) {
//         cout << "YES" << endl;
//         return;
//       } else {
//         cout << "NO" << endl;
//         return;
//       }
//     }
//   }
//   cout << "YES" << endl;
// }

void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  vector<int> b(n);
  map<int, int> backupB;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    backupB[b[i]]++;
  }
  map<int, int> diff;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i])
      diff[b[i]]++;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    if (diff.find(x) != diff.end()) {
      diff[x]--;
      if (diff[x] == 0) {
        diff.erase(x);
      }
      if (i == m - 1) {
        if (diff.size() == 0) {
          cout << "YES\n";
          return;
        } else {
          cout << "NO\n";
          return;
        }
      }
    } else if (backupB.count(x)) {
      if (i == m - 1) {
        if (diff.size() == 0) {
          cout << "YES\n";
          return;
        } else {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}