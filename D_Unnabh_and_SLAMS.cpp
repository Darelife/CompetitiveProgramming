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
  int points = 0;
  // vector<int> aa(10);
  la(i, 10) {
    la(j, 10) {
      char c;
      cin >> c;
      if (c == 'X') {
        if (i == 0 || j == 0)
          points += 1;
        else if (i == 9 || j == 9)
          points += 1;
        else if (i == 1 || j == 1)
          points += 2;
        else if (i == 8 || j == 8)
          points += 2;
        else if (i == 2 || j == 2)
          points += 3;
        else if (i == 7 || j == 7)
          points += 3;
        else if (i == 3 || j == 3)
          points += 4;
        else if (i == 6 || j == 6)
          points += 4;
        else if (i == 4 || j == 4)
          points += 5;
        else if (i == 5 || j == 5)
          points += 5;
      }
    }
  }
  cout << points << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}