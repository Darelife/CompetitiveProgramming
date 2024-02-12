#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define la(i, n) for (ll i = 0; i < n; i++)   // loop around
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
  ll n, q;
  cin >> n >> q;
  ll sum = 0;
  ll d = -1;
  vint v(n);
  la(i, n) {
    cin >> v[i];
    sum += v[i];
  }
  set<ll> s;
  la(i, q) {
    ll c;
    cin >> c;

    if (c == 1) {
      ll t, x;
      cin >> t >> x;
      if (s.find(t) == s.end()) {
        if (d == -1)
          sum = sum - v[t - 1] + x;
        else {
          sum = sum - d + x;
        }
        s.insert(t);
      } else {
        sum = sum - v[t - 1] + x;
      }
      v[t - 1] = x;
    } else {
      ll x;
      cin >> x;
      sum = x * n;
      d = x;
      s.clear();
    }
    cout << sum << endl;
  }
}
//? MIGHT HAVE TO USE PREFIX SUM

// la(i, q) {
//   int sum2 = sum;
//   int c;
//   cin >> c;
//   if (c == 1) {
//     int t, x;
//     cin >> t >> x;
//     sum -= a[t - 1];
//     sum += x;
//   } else {
//     int t;
//     cin >> t;
//     sum = n * t;
//   }
//   cout << sum << endl;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}