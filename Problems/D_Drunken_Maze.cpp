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

struct node {
  int x, y;
  bool operator==(const node& other) const {
    return x == other.x && y == other.y;
  }
  bool operator!=(const node& other) const {
    return !(*this == other);
  }
};

struct val {
  int x, y, dir, steps, dist;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  node start, end;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    // if (a[i] == 'S') start = {}
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') start = { i, j };
      if (a[i][j] == 'T') end = { i, j };
    }
  }

  queue<val> q;
  // q.push({ start.x, start.y, 0, 0, 0 });
  vector<pair<int, int>> dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
  vector<vector<vector<vector<bool>>>> vis(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(4, false))));
  for (int i = 0; i < 4; i++) {
    int xx = start.x + dirs[i].first;
    int yy = start.y + dirs[i].second;
    if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#') {
      q.push({ xx, yy, i, 1, 1 });
      vis[xx][yy][i][1] = true;
    }
  }
  int ans = -1;
  // while (!q.empty()) {
  //   auto [x, y, l, dx, dy] = q.front();
  //   q.pop();

  //   for (auto [ddx, ddy] : dirs) {
  //     int xx = x + ddx, yy = y + ddy;
  //     node sameDir = { x + dx, y + dy };
  //     node next = { xx, yy };
  //     if (a[xx][yy] != '#' && ((sameDir != next) || (sameDir == next && l < 3))) {
  //       if (next == sameDir) {
  //         q.push({ xx, yy, l + 1, ddx, ddy });
  //       } else {
  //         q.push({ xx, yy, 0, ddx, ddy });
  //       }
  //     }
  //   }
  // }
  while (!q.empty()) {
    auto [x, y, dir, steps, dist] = q.front();
    q.pop();
    if (a[x][y] == 'T') {
      cout << dist << endl;
      return;
    }
    if (steps < 3) {
      int xx = x + dirs[dir].first;
      int yy = y + dirs[dir].second;
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#' && !vis[xx][yy][dir][steps + 1]) {
        vis[xx][yy][dir][steps + 1] = true;
        q.push({ xx, yy, dir, steps + 1, dist + 1 });
      }
    }
    for (int i = 0; i < 4; i++) {
      if (i == dir) continue;
      int xx = x + dirs[i].first;
      int yy = y + dirs[i].second;
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#' && !vis[xx][yy][i][1]) {
        vis[xx][yy][i][1] = true;
        q.push({ xx, yy, i, 1, dist + 1 });
      }
    }
  }
  cout << -1 << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}