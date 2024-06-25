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
  int n, m;
  cin >> n >> m;
  // matrix of size n x m
  vector<vector<int>> a(n, vector<int>(m));
  forr(i, n) {
    forr(j, m) {
      char b;
      cin >> b;
      (b == 'W') ? a[i][j] = 1 : a[i][j] = 0;
    }
  }
  // // if 2 corners are 1 and 2 corners are 0, then it is impossible to fill
  // the
  // // rectangle
  // int b = 0, w = 0;
  // if (a[0][0] == 1)
  //   w++;
  // else
  //   b++;

  // if (a[0][m - 1] == 1)
  //   w++;
  // else
  //   b++;

  // if (a[n - 1][0] == 1)
  //   w++;
  // else
  //   b++;

  // if (a[n - 1][m - 1] == 1)
  //   w++;
  // else
  //   b++;

  // if (b == 2 && w == 2)
  //   cout << "NO" << endl;
  // else
  //   cout << "YES" << endl;

  // if an 2 entire edges are of opposite colours, then it is impossible to fill
  // the rectangle

  int bb = 0, ww = 0;
  // top edge
  int b = 0, w = 0;
  forr(i, m) {
    if (a[0][i] == 1)
      w++;
    else
      b++;
  }
  if (b == m)
    bb = 1;
  if (w == m)
    ww = 1;

  // bottom edge
  b = 0, w = 0;
  forr(i, m) {
    if (a[n - 1][i] == 1)
      w++;
    else
      b++;
  }
  if (b == m)
    bb = 1;
  if (w == m)
    ww = 1;

  // left edge
  b = 0, w = 0;
  forr(i, n) {
    if (a[i][0] == 1)
      w++;
    else
      b++;
  }
  if (b == n)
    bb = 1;
  if (w == n)
    ww = 1;

  // right edge
  b = 0, w = 0;
  forr(i, n) {
    if (a[i][m - 1] == 1)
      w++;
    else
      b++;
  }

  if (b == n)
    bb = 1;
  if (w == n)
    ww = 1;

  if (bb && ww)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;

  // cout << "YES" << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}