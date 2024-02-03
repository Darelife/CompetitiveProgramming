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
  // 1 2 1 5
  // 1 2 4 9 10

  // 1 4 4 9 9
  ll n, q;
  cin >> n >> q;
  vill a = {0};
  vill b;

  la(i, n) {
    ll x;
    cin >> x;
    if (i == 0) {
      a.pba(x);
      b.pba(x);
    } else {
      a.pba(a.back() + x);
      b.pba(max(b.back(), x));
    }
  }
  // a -> 1 3 4 9
  // b -> 1 3 3 5

  la(i, q) {
    ll x;
    cin >> x;
    cout << a[upper_bound(allEle(b), x) - b.begin()]
         << " "; // upperBound of 4 in 1 3 3 5 is at index 2 (value = 3)
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