#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define la(i, n) for (int i = 0; i < n; i++)  // loop around
#define ela(i, n) for (int i = 0; i < n; i++) // Equal Loop Around
#define pba push_back
#define pfa push_front
#define popb pop_back
#define popf pop_front
#define gla(i, a, n) for (int i = a; i < n; i++) // general loop around
#define empb emplace_back
#define empf emplace_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()
#define sq(x) ((x) * (x))
#define lasqr(i, a, n)                                                         \
  for (int i = a; i * i <= n; i++) // loop around square root
#define mpair make_pair
#define mtuple make_tuple

typedef vector<int> vint;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void solve() {
  int n, k;
  cin >> n >> k;

  int ans = 1;
  lasqr(i, 1, n) {
    if (n % i == 0) {
      if (i <= k)
        ans = max(i, ans);
      if (n / i <= k)
        ans = max(n / i, ans);
    }
  }

  cout << n / ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}