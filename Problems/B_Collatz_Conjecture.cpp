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

int digitSum(int n) {
  if (n < 10) return n;
  return n % 10 + digitSum(n / 10);
}

vint calculatePowersOfY(int y) {
  vint powers;
  int power = 1;
  while (power <= inf / y) {
    power *= y;
    powers.pba(power);
  }
  return powers;
}

void solve() {
  int x, y, k;
  cin >> x >> y >> k;

  int d = y - x % y;
  if (k < d) {
    cout << x + k << endl;
  } else if (k == d) {
    x += k;
    while (x % y == 0) x /= y;
    cout << x << endl;
  } else {
    while (1) {
      if (x == 1) break;
      if (k >= d) {
        k -= d;
        x += d;
        while (x % y == 0) x /= y;
        d = y - x % y;
      } else {
        x += k;
        k = 0;
        break;
      }
    }
    if (k != 0) cout << k % (y - 1) + 1 << endl;
    else cout << x << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}