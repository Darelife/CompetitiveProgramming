#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
#define lasqr(i, n) for (int i = 0; i * i < n; i++) // loop around square root
#define mpair make_pair
#define mtuple make_tuple

typedef vector<int> vint;
typedef vector<ll> vill;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void solve() {
  int n, m;
  cin >> n >> m;
  map<ll, vector<ll>> mp;

  la(i, n) {
    la(j, m) {
      ll x;
      cin >> x;
      mp[j].pba(x);
    }
  }

  ll ans = 0;

  la(i, m) {
    sort(allEle(mp[i]));
    if (n % 2 == 1) {
      int cnt = 0;
      for (int j = 0; j <= n / 2; j++) {
        // if n == 3 -> 2, 0, -2
        // if n == 5 -> 4, 2, 0, -2, -4
        // if n == 7 -> 6, 4, 2, 0, -2, -4, -6
        ans -= mp[i][j] * (n / 2 - cnt) * 2;
        ans += mp[i][n - j - 1] * (n / 2 - cnt) * 2;
        cnt++;
      }
    } else {
      int cnt = 0;
      for (int j = 0; j < n / 2; j++) {
        // if n == 4 -> 3, 1, -1, -3
        // if n == 6 -> 5, 3, 1, -1, -3, -5
        // if n == 8 -> 7, 5, 3, 1, -1, -3, -5, -7
        ans -= mp[i][j] * (n - 1 - cnt * 2);
        ans += mp[i][n - j - 1] * (n - 1 - cnt * 2);
        cnt++;
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