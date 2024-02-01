#include <bits/stdc++.h>
using namespace std;

// Passed 1/1 test cases

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
  if (n == 1) {
    cout << 1 << endl;
    return;
  } else if (n == 2) {
    cout << -1 << endl;
    return;
  }

  int k = 1;
  int l = (n % 2 == 1) ? n * n / 2 + 2 : n * n / 2 + 1;
  for (int i = 0; i < n * n; i++) {
    if (i % 2 == 0) {
      cout << k << " ";
      k++;
    } else {
      cout << l << " ";
      l++;
    }
    if ((i + 1) % n == 0) {
      cout << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}