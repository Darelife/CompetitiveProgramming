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
  int tries = 0;
  vector<int> a(n);
  la(i, n) { cin >> a[i]; }
  if (a[0] == 1) {
    a[0] = 2;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      if (a[i - 1] == 2) {
        a[i] = 3;
      } else {
        a[i] = 2;
      }
    } else if (a[i - 1] > a[i]) {
      continue;
    } else {
      if (a[i] % a[i - 1] == 0)
        a[i] += 1;
    }
  }

  for (auto &i : a) {
    cout << i << " ";
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