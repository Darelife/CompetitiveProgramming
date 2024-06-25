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
  int n;
  cin >> n;
  vint a(n);
  // map<int, int> m;

  // la(i, n) { cin >> a[i]; }
  // int ans = 0;
  // // while (1) {
  // int trigger = -1;
  // int space = 0;
  // la(i, n) {
  //   if (a[i] == 1 && trigger == -1) {
  //     trigger = 0;
  //   }
  //   if (a[i] == 0 && trigger == 0) {
  //     trigger = 1;
  //     space += 1;
  //   }
  //   if (a[i] == 0 && trigger == 1) {
  //     space += 1;
  //   }
  //   if (a[i] == 1 && trigger == 1) {
  //     trigger = -1;
  //     ans += space;
  //     space = 0;
  //   }
  //   i -= space;
  // }
  // // }
  // cout << ans << endl;

  la(i, n) { cin >> a[i]; }
  int aa = -1, bb = -1;
  la(i, n) {
    if (a[i] == 1 && aa == -1) {
      aa = i;
    }
    if (a[i] == 1) {
      bb = i;
    }
  }

  int ans = 0;
  for (int i = aa; i <= bb; i++) {
    if (a[i] == 0) {
      ans++;
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