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
  int n;
  cin >> n;
  map<double, int> mp;
  int zeroes = 0;
  map<pii, int> zero;
  forr(i, n) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    // pii p = { x - a, y - b };
    // int d = __gcd(abs(p.first), abs(p.second));
    // p.first /= d;
    // p.second /= d;
    // if (p.first == 0) p.second /= abs(p.second);
    // if (p.second == 0) p.first /= abs(p.first);
    // mp[p]++;
    double m = (double)(y - b) / abs(x - a);
    if (m != 0)
      mp[m]++;
    else {
      pii p = { x - a, y - b };
      int d = __gcd(abs(p.first), abs(p.second));
      p.first /= d;
      p.second /= d;
      if (p.first == 0) p.second /= abs(p.second);
      if (p.second == 0) p.first /= abs(p.first);
      zero[p]++;
    }
  }
  for (auto x : zero) {
    if (zero.find({ -1 * x.first.first, -1 * x.first.second }) != zero.end())
      zeroes += x.second * zero[{-1 * x.first.first, -1 * x.first.second}];
  }
  // for (auto x : mp) cout << x.first << " " << x.second << endl;
  int ans = 0;
  for (auto x : mp) {
    // find pii {-x.first.first, -x.first.second} in mp
    if (mp.find(-1 * x.first) != mp.end()) {
      // cout << x.first << " " << x.second << endl;
      // cout << -1 * x.first << " " << mp[-1 * x.first] << endl;
      ans += x.second * mp[-1 * x.first];
    }
  }
  // cout << ans << endl;
  // ans += zeroesC2 /2;
  string s;
  ans += zeroes * (zeroes - 1);
  cout << ans / 2 << endl;

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}