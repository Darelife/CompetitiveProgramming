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

bool check() {
  return 0;
}
void solve() {
  int n, l;
  cin >> n >> l;
  vint a(n);
  vcin(a, n);
  int i = 0, j = n - 1;
  long double p1 = 0, p2 = l, t = 0, v1 = 1, v2 = 1;
  while (i <= j) {
    long double d1 = (a[i] - p1), d2 = (p2 - a[j]);
    long double t1 = d1 / v1, t2 = d2 / v2;
    if (t2 > t1) {
      t += t1;
      p1 = a[i];
      p2 -= v2 * t1;
      v1++;
      i++;
    } else {
      t += t2;
      p2 = a[j];
      p1 += v1 * t2;
      v2++;
      j--;
    }
  }
  t += (p2 - p1) / (v1 + v2); // remaining distance (no flag in between)
  cout << fixed << setprecision(15) << t << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}