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
  int r, c;
  cin >> r >> c;
  if (r == 1 && c == 1) {
    cout << 0 << endl;
    return;
  }
  if (r == 1) {
    for (int i = 2; i <= c + 1; i++) {
      cout << i << " ";
    }
    cout << endl;
    return;
  }
  if (c == 1) {
    for (int i = 2; i <= r + 1; i++) {
      cout << i << endl;
    }
    return;
  }

  vector<vector<int>> mat(r, vector<int>(c, 0));

  if (r <= c) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        mat[i][j] = (i + 1) * (r + j + 1);
      }
    }
  } else {
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < r; j++) {
        mat[j][i] = (i + 1) * (c + j + 1);
      }
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << mat[i][j] << " ";
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