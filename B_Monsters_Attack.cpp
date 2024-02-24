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
  // int n, k;
  // cin >> n >> k;
  // vint a(n), x(n);
  // la(i, n) cin >> a[i];
  // la(i, n) {
  //   int temp;
  //   cin >> temp;
  //   if (temp < 0)
  //     x[i] = (-1) * temp;
  //   else
  //     x[i] = temp;
  // }
  // map<int, int> m;
  // la(i, n) m[x[i]] = a[i];
  // sort(allEle(x));
  // int ans = 0;
  // la(i, n) {

  // }
  // cout << ans << endl;

  int n, k;
  cin >> n >> k;
  vint a(n), x(n);
  la(i, n) cin >> a[i];
  multiset<pair<int, int>> m;
  la(i, n) cin >> x[i], m.insert({abs(x[i]), a[i]});
  int pos = 0;
  int ans = 1;
  while (m.empty() == false) {
    int hit = k;
    while (m.empty() == false && hit > 0) {
      pair<int, int> element = *m.begin();
      m.erase(m.begin());
      if (element.first <= pos) {
        ans = 0;
        break;
      }
      if (hit >= element.second) {
        hit -= element.second;
      } else {
        m.insert({element.first, element.second - hit});
        hit = 0;
      }
    }
    if (ans == 0) {
      break;
    }
    pos += 1;
  }
  cout << (ans ? "YES" : "NO") << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}