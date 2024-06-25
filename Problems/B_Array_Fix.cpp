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
  int n;
  cin >> n;
  vint a(n);
  for (auto &i : a)
    cin >> i;

  vint b;
  // for (int i = 0; i < n; i++) {
  //   if (!i) {
  //     b.pba(a[i]);
  //   } else {
  //     if (a[i] < b[b.size() - 1]) {

  //     }
  //   }
  // }
  b.pba(a[n - 1]);
  for (int i = n - 1 - 1; i >= 0; i--) {
    // if (i == n - 2) {
    //   // b.pba(a[i]);
    // }
    if (a[i] <= b[b.size() - 1]) {
      b.pba(a[i]);
    } else {
      // int c = log10(a[i]) + 1;
      // vint t(c);
      // for (int j = 0; j < c; j++) {
      //   t[j] = a[i] % 10;
      //   a[i] /= 10;
      // }
      b.pba(a[i] % 10);
      b.pba(a[i] / 10);
    }
  }
  vint sb = b;
  sort(allEle(sb));
  forr(i, b.size()) {
    if (b[i] != sb[b.size() - i - 1]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  // string arr[n];
  // forr(i, n) { cin >> arr[i]; }
  // vint t;
  // forr(i, n) {
  //   int len = arr[i].length();
  //   for (int j = 0; j < len; j++) {
  //     t.pba(arr[i][j] - '0');
  //   }
  // }
  // vint st = t;
  // sort(allEle(st));
  // forr(i, t.size()) {
  //   if (t[i] != st[i]) {
  //     cout << "NO" << endl;
  //     return;
  //   }
  // }
  // cout << "YES" << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}