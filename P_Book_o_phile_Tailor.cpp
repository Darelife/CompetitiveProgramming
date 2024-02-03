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
  ll n, x;
  cin >> n >> x;
  vint a(n), b(n), c(n);
  la(i, n) cin >> a[i];
  la(i, n) cin >> b[i];
  la(i, n) cin >> c[i];

  ll ans = 0;

  for (ll i = 0; i < 3; i++) {
    if (i == 1)
      a = b;
    if (i == 2)
      a = c;
    for (ll j = n - 1; j >= 0; j--) {
      if ((x | a[j]) != x) {
        break;
      }
      ans |= a[j];
    }
  }
  if (ans == x) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  // int d = 0;
  // bool ans = false;
  // if (x == 0) {
  //   cout << "YES" << endl;
  //   return;
  // }
  // while (1) {
  //   bool zeroConverted = true;
  //   if (a.size()) {
  //     if (x | a[a.size() - 1] == x) {
  //       d = (d | a[a.size() - 1]);
  //       a.pop_back();
  //       if (d == x) {
  //         ans = true;
  //         break;
  //       }
  //       zeroConverted = false;
  //     }
  //   }
  //   if (b.size()) {
  //     if (x | b[b.size() - 1] == x) {
  //       d = (d | b[b.size() - 1]);
  //       b.pop_back();
  //       if (d == x) {
  //         ans = true;
  //         break;
  //       }
  //       zeroConverted = false;
  //     }
  //   }
  //   if (c.size()) {
  //     if (x | c[c.size() - 1] == x) {
  //       d = (d | c[c.size() - 1]);
  //       c.pop_back();
  //       if (d == x) {
  //         ans = true;
  //         break;
  //       }
  //       zeroConverted = false;
  //     }
  //   }
  //   if (zeroConverted) {
  //     break;
  //   }
  // }
  // if (ans) {
  //   cout << "YES" << endl;
  // } else {
  //   cout << "NO" << endl;
  // }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}