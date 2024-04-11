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
  // writing this cuz im nervous af rn, and can't concentrate
  // a -> n int
  // n>=m
  // b -> m int
  // c -> m int = good if k of c are in b
  // number of c's = ? if we choose c from a (subsegment)
  int n, m, k;
  cin >> n >> m >> k;
  vint a(n), b(m), c(m);
  forr(i, n) cin >> a[i];
  forr(i, m) cin >> b[i];
  sort(allEle(b));
  int ans = 0;
  for (int i = 0; i < n - m + 1; i++) {
    // choose c from a -> subsegment
    forr(j, m) c[j] = a[i + j];
    sort(allEle(c));
    int cnt = 0;
    forr(j, m) {
      if (c[j] == b[j])
        cnt++;
      if (cnt >= k) {
        ans++;
        break;
      }
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