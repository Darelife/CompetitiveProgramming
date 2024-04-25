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
  int n, h;
  cin >> n >> h;
  vint a(n);
  forr(i, n) cin >> a[i];
  //* IMP : Used the help of the editorial
  // Binary Search
  int left = 1, right = 1e18; // limits of h
  while (left <= right) {
    int mid = (left + right) / 2;
    int sum = mid;
    for (int i = 0; i < n - 1; i++) {
      // if (i == n - 1) {
      // sum += mid;
      // break;
      // }
      // else {
      sum += min(mid, a[i + 1] - a[i]);
      // }
    }
    if (sum < h) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << right + 1 << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}