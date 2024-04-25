#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;

const int inf = 1e9 + 5;

void solve() {
  // string a, s;
  // cin >> a >> s;
  // int n = a.size(), m = s.size();
  // string b = "";
  // int i, j;
  // for (i = a.length(), j = s.length(); i >= 0 && j >= 0; i--, j--) {
  //   char x = a[i], y = s[j];
  //   if (x <= y) {
  //     b += x - y;
  //   }
  //   if (x > y) {
  //     if (j > 0 && y != '9') {
  //       if (s[j - 1] == '1') {
  //         b += s[j - 1];
  //         b += y - x;
  //         j--; // to skip the next digit as we just used it here
  //       } else {
  //         cout << -1 << endl;
  //         return;
  //       }
  //     } else {
  //       cout << -1 << endl;
  //       return;
  //     }
  //   }
  // }
  // if (i == -1 && j == -1) {
  //   cout << b << endl;
  //   return;
  // } else {
  //   cout << -1 << endl;
  //   return;
  // }
  int a, s;
  cin >> a >> s;
  vint b;
  while (s) {
    int x = a % 10, y = s % 10;

    if (x <= y)
      b.pba(y - x);
    else {
      s /= 10;
      y += 10 * (s % 10);

      if (x < y && y >= 10 && y <= 18) {
        b.pba(y - x);
      } else {
        cout << -1 << endl;
        return;
      }
    }
    a /= 10;
    s /= 10;
  }
  if (a || s)
    cout << -1 << endl;
  else {
    while (b.back() == 0)
      b.pop_back();
    reforr(i, b.size() - 1) {
      // if (b[i] != 0)
      cout << b[i];
    }
    cout << endl;
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