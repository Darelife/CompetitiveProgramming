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
  // int start = 0;
  // int ans = 0;
  // int n, k;
  // cin >> n >> k;
  // int end = n - 1;
  // vint a(n);
  // forr(i, n) cin >> a[i];
  // forr(i, k) {
  //   if (a[start] <= 0)
  //     start++, ans++;
  //   if (a[end] <= 0)
  //     end--, ans++;
  //   if (start > end) {
  //     cout << n << endl;
  //     return;
  //   }
  //   if (i % 2 == 0) {
  //     a[start]--;
  //     if (i == k - 1 && a[start] == 0) {
  //       ans++;
  //     }
  //   } else {
  //     a[end]--;
  //     if (i == k - 1 && a[end] == 0) {
  //       ans++;
  //     }
  //   }
  //   // for (int j = 0; j < n; j++) {
  //   //   cout << a[j] << " ";
  //   // }
  //   // cout << endl;
  // }
  // // if (a[start] <= 0)
  // //   start++, ans++;
  // // if (a[end] <= 0)
  // //   end--, ans++;
  // cout << ans << endl;
  // int n, k;
  // cin >> n >> k;
  // vint a(n);
  // forr(i, n) cin >> a[i];
  // int ans = 0;
  // int sum = 0;
  // forr(i, n) { sum += a[i]; }
  // vint part1;
  // vint part2;
  // int tempsum = 0;
  // forr(i, n) {
  //   tempsum += a[i];
  //   if (tempsum <= sum / 2) {
  //     part1.pba(a[i]);
  //   } else {
  //     part2.pba(a[i]);
  //   }
  // }

  // cout << ans << "\n";
  int n, k;
  cin >> n >> k;
  vint a(n);
  int p1 = 0;
  int p2 = 0;
  int sum = 0;
  forr(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  int neww = 0;
  for (int i = 0; i < n; i++) {
    p1 += a[i];
    if (p1 > (k + 1) / 2) {
      p1 -= a[i];
      neww = i;
      break;
    }
    if (p1 == (k + 1) / 2) {
      neww = i + 1;
      break;
    }
  }
  for (int i = n - 1; i >= neww; i--) {
    p2 += a[i];
    if (p2 > (k / 2)) {
      p2 -= a[i];
      cout << neww - 1 + (n - i) << endl;
      return;
    }
    if (p2 == (k / 2)) {
      cout << neww + (n - i) << endl;
      return;
    }
  }
  if (sum >= k) {
    cout << n << endl;
    return;
  }
  cout << n << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}