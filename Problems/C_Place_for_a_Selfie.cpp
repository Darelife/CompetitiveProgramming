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
  // cout << "--------------------" << endl;
  // find the roots
  // number of roots = 1 -> tangent
  // number of roots = 2 -> secant
  // number of roots = 0 -> no intersection
  int n, m;
  cin >> n >> m;
  vint s(n);
  vcin(s, n);
  sort(allEle(s));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (s[mid] < b) l = mid + 1;
      else r = mid;
    }
    int ss;
    if (l > 0) {
      ss = (s[l] - b > b - s[l - 1]) ? s[l - 1] : s[l];
    } else {
      ss = s[l];
    }
    // cout << ss << endl;
    if ((ss - b) * (ss - b) < 4 * a * c) cout << "YES" << endl << ss << endl;
    else cout << "NO" << endl;
  }
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}