#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define la(i, a, n) for (int i = a; i < n; i++)      // loop around
#define rla(i, n) for (int i = n; i >= 0; i--)       // reverse loop around
#define ela(i, a, n) for (int i = a; i <= n; i++)    // Equal Loop Around
#define lasqr(i, n) for (int i = 1; i * i <= n; i++) // loop around square root
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vi;

const int inf = 1e9 + 5;

void solve() {
  // 1,3,6,10,15,21,28,36,45,55,...
  // RL = -1, LR = +1
  // 1 -> R
  // 2 -> R[LR]
  // 3 -> RR
  // 4 -> RR[LR]
  // 5 -> RRR[RL]
  // 6 -> RRR
  // 7 -> RRR[LR]
  // 8 -> RRR[LR][LR]

  int n;
  cin >> n;
  if (n < 0)
    n = n * -1;
  // int direct = 0;
  // int steps = 0;
  // int lastAddition = 0;
  // while (direct < n) {
  //   lastAddition++;
  //   steps++;
  //   direct += lastAddition;
  // }
  // if (direct == n) {
  //   cout << steps << endl;
  // } else if (direct - n == 1 || n - (direct - lastAddition) == 1) {
  //   cout << steps + 1 << endl;
  // } else if ((direct - n) % 2 == 0) {
  //   cout << steps << endl;
  // } else {
  //   cout << steps + 2 << endl;
  // }
  if (n == 0) {
    cout << 0 << endl;
    return;
  }

  int ans = 0;
  for (int i = 1, pos = 1;; i++, pos += i) {
    if (pos == n || (pos > n && (pos - n) % 2 == 0)) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}