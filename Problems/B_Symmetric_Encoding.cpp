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
  string s;
  cin >> s;
  // vint a(26, 0);
  // for (int i = 0; i < n; i++) {
  //   a[s[i] - 'a'] = 1;
  // }
  // vector<char> sorted;
  // for (int i = 0; i < 26; i++) {
  //   if (a[i] == 1) {
  //     sorted.pba(i + 'a');
  //   }
  // }
  // string ans = "";
  // for (int i = 0; i < n; i++) {
  //   ans += sorted[n - 1 - distance(sorted.begin(), find(allEle(sorted), s[i]))];
  // }
  // cout << ans << endl;
  string t = s;
  sort(allEle(t));
  t.erase(unique(allEle(t)), t.end());
  for (char& c : s) {
    int p = find(allEle(t), c) - t.begin();
    p = t.length() - p - 1;
    cout << t[p];
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