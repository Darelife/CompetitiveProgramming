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
//   int ans = 0;
//   // int posStarted = 0;
//   // for (int i = 0; i < n; i++) {
//   //   if (a[i] > 0) {
//   //     posStarted = 1;
//   //     ans += a[i];
//   //   } else if (a[i] < 0 && posStarted == 0) {
//   //     ans += abs(a[i]);
//   //   } else if (a[i] < 0 && posStarted == 1) {
//   //     ans = abs(ans + (a[i]));
//   //   }
//   // }
//   int small = 0;
//   for (int i = 0; i < n; i++) {
//     if (a[i] < 1)
//       small++;
//   }
//   if (small == n) {
//     for (int i = 0; i < n; i++) {
//       ans += abs(a[i]);
//     }
//   } else {
//     forr(i, n) {
//       if (ans + a[i] < 0) {
//         if (a[i + 1] > 0) {
//           ans = abs(ans + a[i]);
//         } else if (i < n - 1 && a[i + 1] < 0) {
//           ans += a[i];
//         } else ans = abs(ans + a[i]);
//       } else ans += a[i];
//     }
//   }
//   cout << abs(ans) << endl;
// }

void solve() {
  int n; cin >> n;
  vint a(n), c1(n + 1, 0), c2(n + 1, 0); vcin(a, n);
  forr(i, n) { c2[i + 1] = c2[i] + a[i]; c1[i + 1] = max(c1[i] + a[i], abs(c2[i] + a[i])); }
  cout << c1[n] << endl;
}


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}