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

// NEED TO SOLVE THIS QUESTION AGAIN
void solve() {
  int n, k;
  cin >> n >> k;
  int l = 1, r = 2 * n - 1;
  int ans = 2 * n - 1;
  int over;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (mid >= n) {
      over = ((n * (n + 1) >> 1) + ((n - 1) * (n) >> 1) -
              ((2 * n - 1 - mid) * (2 * n - mid) >> 1)) >= k;
    } else {
      over = (mid * (mid + 1) >> 1) >= k;
    }
    if (over) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}