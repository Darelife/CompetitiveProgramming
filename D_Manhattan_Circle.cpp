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
  int a, b;
  cin >> a >> b;
  int longestHash = 0;
  pii start = { 0,0 };
  vector<vector<char>> v(a, vector<char>(b, '.'));
  for (int i = 0; i < a; i++) {
    int lhash = 0;
    pii lend = { 0,0 };
    for (int j = 0; j < b; j++) {
      char t;
      cin >> t;
      v[i][j] = t;
      if (t == '#') {
        lhash++;
        lend = { i,j };
      }
    }
    // cout << endl;
    if (lhash > longestHash) {
      longestHash = lhash;
      start = lend; // making the start, the end of the thing
    }
    // cout << lhash << " " << longestHash << " " << start.first << " " << start.second << endl;
  }
  int x = start.first + 1;
  int y = start.second + 1;
  y -= longestHash / 2;
  cout << x << " " << y << endl;
  // cout << " ----------- " << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}