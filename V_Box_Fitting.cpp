#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define la(i, n) for (int i = 0; i < n; i++)       // loop around
#define ela(i, n) for (int i = 0; i < n; i++)      // Equal Loop Around
#define rla(i, n) for (int i = n - 1; i >= 0; i--) // reverse loop around
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
  int n, w;
  cin >> n >> w;
  vint a(32, 0);
  la(i, n) {
    int x;
    cin >> x;
    a[log2(x)] += 1;
  }

  int h = 1, space = w;
  la(i, n) {
    int t = -1;
    rla(j, 31) {
      if ((1 << j) <= space && a[j] != 0) {
        t = j;
        break;
      }
    }
    if (t == -1) {
      h++;
      space = w;
      rla(j, 31) {
        if ((1 << j) <= space && a[j] != 0) {
          t = j;
          break;
        }
      }
    }
    space -= (1 << t);
    a[t]--;
  }
  cout << h << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}