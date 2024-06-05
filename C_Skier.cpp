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
  string s;
  cin >> s;
  int n = s.length();
  pii cur = { 0, 0 };
  set<pair<pii, pii>> path;
  int ans = 0;
  forr(i, n) {
    pii init = cur;
    if (s[i] == 'N') {
      cur.second++;
    } else if (s[i] == 'S') {
      cur.second--;
    } else if (s[i] == 'E') {
      cur.first++;
    } else {
      cur.first--;
    }
    if (path.count({ init, cur }) || path.count({ cur, init })) {
      ans++;
    } else ans += 5;
    path.insert({ init, cur });
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}