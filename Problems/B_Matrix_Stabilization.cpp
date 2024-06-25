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

int digitSum(int n) {
  if (n < 10) return n;
  return n % 10 + digitSum(n / 10);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  forr(i, n) {
    forr(j, m) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int maxValue = 0;
      if (i > 0) maxValue = max(maxValue, a[i - 1][j]);
      if (i < n - 1) maxValue = max(maxValue, a[i + 1][j]);
      if (j > 0) maxValue = max(maxValue, a[i][j - 1]);
      if (j < m - 1) maxValue = max(maxValue, a[i][j + 1]);
      a[i][j] = min(a[i][j], maxValue);
    }
  }
  // forr(i, 1) {
  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < m; j++) {
  //       int flag = 1;
  //       int maxxDiff = 1;
  //       if (i != 0) {
  //         if (a[i][j] <= a[i - 1][j]) {
  //           flag = 0;
  //           maxxDiff = max(maxxDiff, a[i - 1][j] - a[i][j] + 1);
  //         }
  //       }
  //       if (i != n - 1) {
  //         if (a[i][j] <= a[i + 1][j]) {
  //           flag = 0;
  //           maxxDiff = max(maxxDiff, a[i + 1][j] - a[i][j] + 1);
  //         }
  //       }
  //       if (j != 0) {
  //         if (a[i][j] <= a[i][j - 1]) {
  //           flag = 0;
  //           maxxDiff = max(maxxDiff, a[i][j - 1] - a[i][j] + 1);
  //         }
  //       }
  //       if (j != m - 1) {
  //         if (a[i][j] <= a[i][j + 1]) {
  //           flag = 0;
  //           maxxDiff = max(maxxDiff, a[i][j + 1] - a[i][j] + 1);
  //         }
  //       }
  //       if (i != 0 && j != 0) {
  //         if (a[i][j] <= a[i - 1][j - 1]) {
  //           flag = 0;
  //           maxxDiff = max(maxxDiff, a[i - 1][j - 1] - a[i][j] + 1);
  //         }
  //       }
  //       if (i != 0 && j != m - 1) {
  //         if (a[i][j] <= a[i - 1][j + 1]) {
  //           flag = 0;
  //           maxxDiff = max(maxxDiff, a[i - 1][j + 1] - a[i][j] + 1);
  //         }
  //       }
  //       if (i != n - 1 && j != 0) {
  //         if (a[i][j] <= a[i + 1][j - 1]) {
  //           flag = 0;
  //           maxxDiff = max(maxxDiff, a[i + 1][j - 1] - a[i][j] + 1);
  //         }
  //       }
  //       if (i != n - 1 && j != m - 1) {
  //         if (a[i][j] <= a[i + 1][j + 1]) {
  //           flag = 0;
  //           maxxDiff = max(maxxDiff, a[i + 1][j + 1] - a[i][j] + 1);
  //         }
  //       }
  //       // cout << maxxDiff << " ";
  //       if (flag) {
  //         a[i][j] -= maxxDiff;
  //       }
  //     }
  //   }
  // }
  // cout << endl;
  forr(i, n) {
    forr(j, m) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}