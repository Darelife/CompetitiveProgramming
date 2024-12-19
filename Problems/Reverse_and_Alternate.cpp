#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  string pat1, pat2;
  forr(i, n) pat1 += (i % 2) % 2 + '0';
  forr(i, n) pat2 += (i % 2 + 1) % 2 + '0';

  vector<int> a1, a2; // indices of mismatched characters
  forr(i, n) {
    if (s[i] != pat1[i]) a1.pba(i);
    if (s[i] != pat2[i]) a2.pba(i);
  }

  if (a1.empty() || a2.empty()) {
    cout << "Yes\n";
    return;
  }

  int flag = 1;
  int l = a1.front(), r = a1.back();
  string temp = s;
  reverse(temp.begin() + l, temp.begin() + r + 1);
  forr(i, temp.size()) {
    if (temp[i] != pat1[i]) { flag = 0; break; }
  }
  if (flag) {
    cout << "Yes\n";
    return;
  }

  flag = 1;
  l = a2.front(), r = a2.back();
  temp = s;
  reverse(temp.begin() + l, temp.begin() + r + 1);
  forr(i, temp.size()) {
    if (temp[i] != pat2[i]) { flag = 0; break; }
  }
  if (flag) {
    cout << "Yes\n";
    return;
  }

  cout << "No\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  forr(i, t) {
    solve();
  }
  return 0;
}
