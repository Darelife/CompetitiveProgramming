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
  int n, k;
  cin >> n >> k;
  int a = log2(k) + 1; // max number of bits
  if (n == 1) {
    cout << k << endl;
    return;
  }
  // try to use elements like, 1, 3(11), 7(111), 15(1111), ...
  // 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, ...
  int b = (1 << a) - 1;
  if (k > b) {
    cout << -1 << endl;
    return;
  }
  if (k == b) {
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        cout << k << endl;
      } else {
        cout << 0 << " ";
      }
    }
    return;
  }
  // cout << 1 << endl;
  int aa = (1 << (a - 1)) - 1;
  vint ans(n);
  int tn = n;
  int t = (1 << (a - 2));
  while (tn--) {
    if (tn == 0 && k > 0) {
      ans[tn] = k;
      k = 0;
    } else if (k >= aa) {
      ans[tn] = aa;
      k -= aa;
    } else {
      ans[tn] = k;
      k = 0;
    }
    // cout << "k: " << k << " ans[tn]: " << ans[tn] << " tn: " << tn << endl;
  }
  if (k) {
    cout << -1 << endl;
    return;
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}