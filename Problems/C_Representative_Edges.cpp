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
  int ans = inf;
  if (n <= 2) {
    cout << 0 << endl;
    return;
  }
  // min number of changes required to make A an AP....we can basically do brute force
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      // assuming i and j to be the correct points, d = (a[j] - a[i]) / (j - i)
      double d = (double)(a[j] - a[i]) / (j - i);
      int tempAns = 0;
      for (int k = 0; k < n; k++) {
        if (a[i] + d * (k - i) != a[k]) {
          tempAns++;
        }
      }
      ans = min(ans, tempAns);
    }
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