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
  vint a(n);
  vcin(a, n);
  vint b(n + 1);
  vcin(b, n + 1);
  int b_end = b.back();
  int ans = 0;
  int done = 0;
  int add = inf;
  for (int i = 0; i < n; i++) {
    ans += abs(a[i] - b[i]);
    if (b_end >= min(a[i], b[i]) and b_end <= max(a[i], b[i])) { done = 1; }
    add = min(add, abs(a[i] - b_end));
    add = min(add, abs(b[i] - b_end));
  }
  if (done) {
    cout << ans + 1 << endl;
  } else {
    cout << ans + 1 + add << endl;
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