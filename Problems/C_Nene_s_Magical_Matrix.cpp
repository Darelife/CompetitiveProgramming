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
  // int n;
  // cin >> n;
  // vint a(n * n);
  // int sum = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     a[(i - 1) + (j - 1) * n] = max(i, j);
  //     sum += a[(i - 1) + (j - 1) * n];
  //   }
  // }
  // cout << sum << " " << 2 * n - 1 << endl;
  // for (int i = 1; i <= 2 * n - 1; i++) {
  //   if (i <= n) {
  //     cout << 1 << " " << i << " ";
  //     for (int j = 1; j <= n; j++) {
  //       cout << j << " ";
  //     }
  //     cout << endl;
  //   } else {
  //     cout << 2 << " " << i - n << " ";
  //     for (int j = 1; j <= n; j++) {
  //       cout << a[(j - 1) + (i - n - 1) * n] << " ";
  //     }
  //     cout << endl;
  //   }

  // cout << sum << " " << 2 * n - 1 << endl;
  // for (int i = 1; i <= 2 * n - 1; i++) {
  //   if (i <= n) {
  //     cout << 1 << " " << i << " ";

  //     for (int j = 1; j <= n; j++) {
  //       cout << a[i + j * n] << " ";
  //     }
  //   } else {
  //     cout << 2 << " " << i - n << " ";
  //     for (int j = 1; j <= n; j++) {
  //       cout << a[i + j * n] << " ";
  //     }
  //   }
  //   cout << endl;
  // }

  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 1 << " " << 1 << endl;
    return;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += (2 * i - 1) * i;
  }
  cout << sum << " " << 2 * n << endl;
  for (int i = 2 * n; i >= 1; i--) {
    if (!(i % 2)) {
      cout << 1 << " " << i / 2 << " ";
      for (int j = 1; j <= n; j++) {
        cout << j << " ";
      }
      cout << endl;
    } else {
      cout << 2 << " " << i / 2 + i % 2 << " ";
      for (int j = 1; j <= n; j++) {
        cout << j << " ";
      }
      cout << endl;
    }
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