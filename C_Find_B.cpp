#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define int long long
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
#define lasqr(i, n) for (int i = 0; i * i < n; i++) // loop around square root
#define mpair make_pair
#define mtuple make_tuple

typedef vector<int> vint;
typedef vector<ll> vill;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> c(n + 1), pre(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    pre[i] = pre[i - 1] + c[i];
    s[i] = s[i - 1] + (c[i] == 1 ? 2 : 1); // Same as pre, but replace 1 with 2.
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "NO\n";
      continue;
    }
    if (pre[r] - pre[l - 1] < s[r] - s[l - 1])
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}