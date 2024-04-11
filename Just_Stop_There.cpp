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
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  int ans = 10;

  for (int i = 0; i < 10; i++) {
    if (s[i] == '1') {
      if (i % 2 == 0) {
        a++;
      } else {
        b++;
      }
    }
    // if b can't catch up with A
    if (i == 5 && (a - b >= 3 || b - a >= 3)) {
      ans = 6;
      break;
    }
    if (i == 6 && (a - b >= 3 || b - a >= 2)) {
      ans = 7;
      break;
    }
    if (i == 7 && (a - b >= 2 || b - a >= 2)) {
      ans = 8;
      break;
    }
    if (i == 8 && (a - b >= 2 || b - a >= 1)) {
      ans = 9;
      break;
    }
  }
  cout << ans << endl;

  // for (int i = 0; i < 10; i++) {
  //   if (i % 2 == 0) {
  //     if (s[i] == '1') {
  //       a++;
  //     }
  //   } else {
  //     if (s[i] == '1') {
  //       b++;
  //     }
  //   }
  //   if (a > b + n - i - 1) {
  //     ans = i;
  //     break;
  //   }
  //   if (b > a + n - i - 1) {
  //     ans = i;
  //     break;
  //   }
  // }
  // if (ans == 0) {
  //   cout << 10 << endl;
  //   return;
  // }
  // cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}