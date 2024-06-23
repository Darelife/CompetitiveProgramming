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

void solve() {
  int n, k;
  cin >> n >> k;
  vint a(n);
  vcin(a, n);
  // vint ans(k);
  // int maxAns = 0;
  // for (int i = 0; i < k; i++) {
  //   int cnt = 0;
  //   for (int j = i; j < n; j += k) {
  //     if (a[j] == 1) {
  //       cnt++;
  //     }
  //   }
  //   // ans[i] = cnt;
  //   int c = max(cnt, n / k - cnt);
  //   maxAns = max(maxAns, c);
  // }
  // cout << maxAns << endl;
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if ((j + i) % k != 0) {
        cnt += a[j];
      }
    }
    ans = max(ans, abs(cnt));
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}