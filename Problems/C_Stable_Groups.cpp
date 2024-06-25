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
  int n, k, x;
  cin >> n >> k >> x;
  vint a(n);
  // int t = k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(allEle(a));

  vint b;
  forr(i, n - 1) {
    int diff = a[i + 1] - a[i];
    if (diff > x) {
      int add = (diff - 1) / x;
      b.pba(add);
    }
  }

  sort(allEle(b));

  int ans = (b.size() + 1);

  forr(i, b.size()) {
    if (k >= b[i]) {
      k -= b[i];
      ans--;
    } else
      break;
  }
  cout << ans << endl;

  // sort(allEle(a));
  // for (int i = 0; i < n; i++) {
  //   if (i) {
  //     int diff = a[i] - a[i - 1];
  //     if (diff > x && k > 0) {
  //       int add = (diff - 1) / x;
  //       if (add <= k) {
  //         k -= add;
  //       }
  //     }
  //   }
  // }
  // int ans = 0;
  // for (int i = 1; i < a.size(); i++) {
  //   if (a[i] - a[i - 1] > x) {
  //     ans++;
  //   }
  // }
  // // if ((ans - (t - k) + 1) <= 0)
  // cout << (((ans - (t - k) + 1) > 0) ? ans - (t - k) + 1
  //                                    : ((ans - 1 > 0) ? ans - 1 : n - 1))
  //      << endl;
  // // else cout << ans + 1 << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}