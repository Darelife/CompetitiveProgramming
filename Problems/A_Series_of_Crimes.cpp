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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char t;
      cin >> t;
      if (t == '*') {
        a[i][j] = 1;
      } else {
        a[i][j] = 0;
      }
    }
  }
  vector<pii> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        p.pba({ i, j });
      }
    }
  }
  map<int, int> x, y;
  for (auto& point : p) {
    x[point.first]++;
    y[point.second]++;
  }
  int fourth_x, fourth_y;
  for (auto& point : p) {
    if (x[point.first] == 1) {
      fourth_x = point.first;
    }
    if (y[point.second] == 1) {
      fourth_y = point.second;
    }
  }
  cout << fourth_x + 1 << " " << fourth_y + 1 << endl;

  // In your solve function, call the above function like this:
  // pii fourthPoint = findFourthPoint(p);

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}