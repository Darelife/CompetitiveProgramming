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
  int n, m;
  cin >> n >> m;
  vint p(n + m + 1);
  vcin(p, n + m + 1);
  vint t(n + m + 1);
  vcin(t, n + m + 1);
  vector<pair<int, int>> stuff;
  for (int i = 0; i < n + m + 1; i++) {
    stuff.push_back({ p[i], t[i] });
  }
  // sort stuff on the basis of p[i]
  sort(allEle(stuff));

  // int pp = 0, tt = 0;
  // for (int i = 0; i < n; i++) {
  //   pp += stuff[i].first;
  // }
  // for (int i = n + 1; i < n + m + 1; i++) {
  //   tt += stuff[i].second;
  // }

  // // -------------

  // for (int i = 0; i < n + m + 1; i++) {
  //   if (i < n) {
  //     cout << pp + tt - stuff[i].first + stuff[n].first << " ";
  //   } else if (i == n) {
  //     cout << pp + tt << " ";
  //   } else if (i > n) {
  //     cout << pp + tt - stuff[i].second + stuff[n].second << " ";
  //   }
  // }
  // cout << endl;
  int pp = 0, tt = 0;
  int cntp = 0, cntt = 0;
  vint status(n + m + 1), statusTfirst(n + m + 1);

  // P first
  for (int i = 0; i < n + m + 1; i++) {
    if (p[i] > t[i] && cntp <= n) pp += p[i], cntp += 1, status[i] = 1;
    else if (p[i] < t[i] && cntt < m) pp += t[i], cntt += 1, statusTfirst[i] = 0;
    else if (cntp <= n) pp += p[i], cntp += 1, status[i] = 1;
    else pp += t[i], cntt += 1, statusTfirst[i] = 0;
  }

  cntp = 0, cntt = 0;
  // T first
  for (int i = 0; i < n + m + 1; i++) {
    if (t[i] > p[i] && cntt <= m) tt += t[i], cntt += 1, statusTfirst[i] = 0;
    else if (t[i] < p[i] && cntp < n) tt += p[i], cntp += 1, status[i] = 1;
    else if (cntt <= m) tt += t[i], cntt += 1, statusTfirst[i] = 0;
    else tt += p[i], cntp += 1, status[i] = 1;
  }

  for (int k = 0; k < n + m + 1; k++) {
    if (status[k]) cout << pp - p[k];
    else if (statusTfirst[k] == 0) cout << tt - t[k];
    cout << " ";
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