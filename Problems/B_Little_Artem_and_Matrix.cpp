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
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;


const int inf = 1e9 + 5;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n, vector<int>(m, 0));
  int rowShifted = 0, colShifted = 0;
  // WE NEED TO GET THE INPUT IN REVERSE ORDER
  vector<vector<int>> h;
  forr(i, q) {
    int x;
    cin >> x;
    if (x == 1) {
      int t;
      cin >> t;
      vint hh = { x, t };
      h.pba(hh);
    } else if (x == 2) {
      int t;
      cin >> t;
      vint hh = { x, t };
      h.pba(hh);
    } else {
      int r, c, v;
      cin >> r >> c >> v;
      vint hh = { x, r, c, v };
      h.pba(hh);
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    int x = h[i][0];
    // cout << x << endl;
    if (x == 1) {
      int t = h[i][1];
      t--;
      vint rr = a[t];
      a[t][0] = rr[m - 1];
      forr(j, m) {
        if (j == 0) continue;
        a[t][j] = rr[j - 1];
      }
    } else if (x == 2) {
      int t = h[i][1];
      t--;
      vint cc(n);
      forr(j, n) {
        cc[j] = a[j][t];
      }
      a[0][t] = cc[n - 1];
      forr(j, n) {
        if (j == 0) continue;
        a[j][t] = cc[j - 1];
      }
    } else if (x == 3) {
      // cout << 1;
      int r = h[i][1], c = h[i][2], v = h[i][3];
      // cin >> r >> c >> v;
      a[r - 1][c - 1] = v;
    }
  }
  forr(i, n) {
    forr(j, m) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}