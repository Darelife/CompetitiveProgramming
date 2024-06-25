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
  vector<pii> a(n);
  vector<pii> pre(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    if (i == 0) pre[i] = a[i];
    else pre[i] = { pre[i - 1].first + a[i].first, i };
  }

  sort(allEle(a));

  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    int sum = a[mid].first;
    int tt = 0;
    for (int i = 0; i < n; i++) {
      if (i == mid) continue;
      if (sum >= a[i].first) sum += a[i].first;
      else {
        tt = 1;
        break;
      }
    }
    if (tt == 0) r = mid;
    else l = mid + 1;
  }
  vint ans;
  for (int i = l; i < n; i++) {
    ans.pba(a[i].second + 1);
  }
  sort(allEle(ans));
  cout << ans.size() << endl;
  vpin(ans);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}