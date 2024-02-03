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
  // int w, h;
  // cin >> w >> h;
  // vector<int> side1;
  // vector<int> side2;
  // vector<int> side3;
  // vector<int> side4;
  // int k1, k2, k3, k4;
  // cin >> k1;
  // for (int i = 0; i < k1; i++) {
  //   int x;
  //   cin >> x;
  //   side1.push_back(x);
  // }
  // cin >> k2;
  // for (int i = 0; i < k2; i++) {
  //   int x;
  //   cin >> x;
  //   side2.push_back(x);
  // }
  // cin >> k3;
  // for (int i = 0; i < k3; i++) {
  //   int x;
  //   cin >> x;
  //   side3.push_back(x);
  // }
  // cin >> k4;
  // for (int i = 0; i < k4; i++) {
  //   int x;
  //   cin >> x;
  //   side4.push_back(x);
  // }
  // sort(allEle(side1));
  // sort(allEle(side2));
  // sort(allEle(side3));
  // sort(allEle(side4));

  // int ans1 = (side1[k1 - 1] - side1[0]) * (side3[0]);
  // int ans2 = (side2[k2 - 1] - side2[0]) * (side4[0]);
  // int ans3 = (side1[k1 - 1] - side1[0]) * (side3[k3 - 1]);
  // int ans4 = (side2[k2 - 1] - side2[0]) * (side4[k4 - 1]);
  // int ans5 = (side3[k3 - 1] - side3[0]) * (side1[0]);
  // int ans6 = (side4[k4 - 1] - side4[0]) * (side2[0]);
  // int ans7 = (side3[k3 - 1] - side3[0]) * (side1[k1 - 1]);
  // int ans8 = (side4[k4 - 1] - side4[0]) * (side2[k2 - 1]);
  // cout << max({ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8}) << endl;

  int w, h;
  cin >> w >> h;
  // int ans = 0;
  // la(i, 4) {
  //   int lside, l = 0;
  //   cin >> lside;
  //   la(j, lside) {
  //     int element;
  //     cin >> element;
  //     if (j == 0)
  //       l = element;
  //     else
  //       l = max(l, element);
  //   }
  //   if (i == 0 || i == 1)
  //     ans = max(ans, l * h);
  //   else
  //     ans = max(ans, l * w);
  // }
  // cout << ans << endl;

  int ans = 0;
  int n;
  la(i, 4) {
    cin >> n;
    int d = 0;
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