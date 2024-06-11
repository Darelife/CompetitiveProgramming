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
  int a;
  string n;
  cin >> a;
  n = to_string(a);
  if (n[n.length() - 1] == '9') {
    cout << "NO" << endl;
    return;
  }
  if (n[0] != '1') {
    cout << "NO" << endl;
    return;
  }
  for (int i = 0; i < n.length() - 1; i++) {
    if (n[i] == '0') {
      cout << "NO" << endl;
      return;
    }
  }

  string smallRange = "", largeRange = "";
  for (int i = 0; i < n.length() - 1; i++) {
    smallRange += '5', largeRange += '9';
  }
  int smallRangee = stoll(smallRange), largeRangee = stoll(largeRange);
  int smallRangeee = a - smallRangee, largeRangeee = a - largeRangee;

  int n_smallRange = to_string(smallRangeee).length();
  int n_largeRange = to_string(largeRangeee).length();

  if (n_smallRange > n.length() - 1 && n_largeRange > n.length() - 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  // if (n.length() > 2 && n[n.length() - 1] == '0' && n[n.length() - 2] == '0') {
  //   cout << "NO" << endl;
  //   return;
  // }
  // for (int i = 0; i < n.length() - 1; i++) {
  //   if (n[i] == 0 && n[i + 1] == 0) {
  //     cout << "NO" << endl;
  //     return;
  //   }
  // }
  // cout << "YES" << endl;

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}