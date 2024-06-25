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
  int n, d;
  cin >> n >> d;
  vector<int> a;
  int wins = 0;
  la(i, n) {
    int temp;
    cin >> temp;
    a.pba(temp);
  }
  sort(allEle(a));
  // int endPoint = 0;
  // for (int i = n - 1; i >= endPoint; i--) {
  //   // int playersReq = (d+1)/a[i] + 1
  //   int playersReq = (d + 1 + a[i] - 1) / a[i];
  //   if (a.size() - (endPoint)-1 >= playersReq) {
  //     wins++;
  //     endPoint += playersReq - 1;
  //   }
  // }
  int i = n - 1;
  while (1) {
    int reqPlayers;
    if (a[i] <= d)
      reqPlayers = (d) / a[i] + 1;
    else
      reqPlayers = 1;
    if (reqPlayers <= n) {
      n -= reqPlayers;
      i--;
      wins++;
    } else
      break;
  }
  cout << wins << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}