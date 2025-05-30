#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define f(i, a, b) for (int i = a; i < b; i++)
#define pba push_back

typedef vector<int> vint;
#define vcin(vint, n) f(i, 0, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;

#define endl '\n'
const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

// ig i could have used a pair, but a struct makes me feel powerful!!!!
struct node {
  int x, y;
};

void dfs(vector<vector<int>>& vis, vector<vector<char>>& grid, int x, int y, int px, int py, int& ans) {
  vis[x][y] = 1;
  int n = grid.size(), m = grid[0].size();
  node dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

  for (int i = 0; i < 4; i++) {
    int dx = x + dir[i].x, dy = y + dir[i].y;
    if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
      if (grid[dx][dy] == grid[x][y]) {
        if (!vis[dx][dy]) {
          dfs(vis, grid, dx, dy, x, y, ans);
        } else if (dx != px && dy != py) {
          ans = true;
          return;
        }
      }
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int ans = 0;
  vector<vector<int>> vis(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        dfs(vis, grid, i, j, -1, -1, ans);
      }
      if (ans) break;
    }
    if (ans) break;
  }
  if (!ans) {
    cout << "No" << endl;
    return;
  }
  cout << "Yes" << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}