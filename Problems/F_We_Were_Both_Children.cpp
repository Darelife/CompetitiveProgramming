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
int vlcm(vint& a) {
  int n = a.size();
  int ans = a[0];
  for (int i = 1; i < n; i++) {
    ans = (a[i] * ans) / __gcd(a[i], ans);
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  vint a(n);
  vint count(n + 1, 0); // forgot about this initially, was causing an error

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x <= n) {
      ++count[x];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      mp[j] += count[i];
    }
  }

  int ans = 0;
  for (auto i : mp) {
    ans = max(ans, i.second);
  }

  // cout << endl;
  // cout << endl;
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