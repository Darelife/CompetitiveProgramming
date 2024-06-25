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

const int inf = 1e9 + 5;

void solve() {
  // cout << "tt\n";
  int n, c, d;
  cin >> n >> c >> d;
  vint a(n * n);
  forr(i, n * n) cin >> a[i];
  sort(allEle(a));
  // int m = a[0];
  vint ee;
  // mat[0][0] = a[0];
  // for (int i = 1; i < n; i++) {
  //   mat[i][0] = mat[i - 1][0] + d;
  //   mat[0][i] = mat[0][i - 1] + c;
  // }
  // for (int i = 1; i < n; i++) {
  //   for (int j = 1; j < n; j++) {
  //     mat[i][j] = (mat[i - 1][j] + d == mat[i][j - 1] + c) ? mat[i - 1][j] +
  //     d
  //                                                          : mat[i][j - 1] +
  //                                                          c;
  //   }
  // }
  int x = a[0];
  forr(i, n) {
    x = a[0] + i * c;
    forr(j, n) { ee.pba(x + j * d); }
  }
  // vint cc(n * n);
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cc.pba(mat[i][j]);
  //   }
  // }
  sort(allEle(ee));
  // forr(i, n * n) cout << ee[i] << " ";
  // cout << "\n";
  // forr(i, n * n) cout << a[i] << " ";
  // cout << "\n";
  int index = 0;
  forr(i, n * n) {
    if (ee[i] != a[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  // int index = 0;
  // forr(i, n) {
  //   forr(j, n) {
  //     if (mat[i][j] != a[index]) {
  //       cout << "NO\n";
  //       return;
  //     }
  //     index += 1;
  //   }
  // }
  // cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // int t;
  // cout << "tt\n";
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}