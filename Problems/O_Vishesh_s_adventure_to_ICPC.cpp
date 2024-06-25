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
  string n;
  cin >> n;
  // if n1 = 101, n2 = 110, n3 = 011, n4 = 101 (right shift)
  map<int, char> m;
  la(i, n.size()) {
    la(j, n.size()) {
      // Make it right shift
      m[i * n.size() + j] = n[(j - i + n.size()) % n.size()];
    }
  }

  // for (auto i : m) {
  //   cout << i.second;
  //   if (i.first % n.size() == n.size() - 1) {
  //     cout << endl;
  //   }
  // }
  // cout << endl;

  int ans = 0;
  la(i, n.size()) {
    int cnt = 0;
    la(j, n.size()) {
      if (m[i * n.size() + j] == '1') {
        cnt++;
      }
    }
    ans = max(ans, cnt);
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