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
  // int h, n;
  // cin >> h >> n;
  // vint a(n);
  // int maxHit = 0;
  // int minHit = inf;
  // for (int i = 0; i < n; i++) {
  //   cin >> a[i];
  //   maxHit = max(maxHit, a[i]);
  //   minHit = min(minHit, a[i]);
  // }
  // vint c(n);
  // vcin(c, n);




  // int ans = 0;
  // ans += h / maxHit;
  // if (h % maxHit != 0) {
  //   ans++;
  // }
  // cout << ans << endl;
  // int h, n;
  // cin >> h >> n;
  // vint a(n), c(n);
  // vcin(a, n);
  // vcin(c, n);

  // vector<pii> attacks(n);
  // for (int i = 0; i < n; ++i) {
  //   attacks[i] = { 1, i };
  // }

  // sort(allEle(attacks));

  // queue<pii> q;
  // for (auto& attack : attacks) {
  //   q.push(attack);
  // }

  // int time = 0;
  // while (h > 0) {
  //   time = q.front().first;

  //   while (!q.empty() && q.front().first == time) {
  //     int i = q.front().second;
  //     q.pop();

  //     h -= a[i];

  //     if (h > 0) {
  //       q.push({ time + c[i], i });
  //       sort(allEle(attacks));
  //     }
  //   }
  // }

  // cout << time << endl;
  int h, n;
  cin >> h >> n;

  vector<int> a(n);
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  priority_queue<pii, vector<pii>, greater<pii>> attacks;

  for (int i = 0; i < n; ++i) {
    attacks.push({ 1, i });
  }

  int time = 0;
  while (h > 0) {
    time = attacks.top().first;
    while (!attacks.empty() && attacks.top().first == time) {
      int attackIndex = attacks.top().second;
      attacks.pop();

      h -= a[attackIndex];

      attacks.push({ time + c[attackIndex], attackIndex });
    }
  }

  cout << time << endl;
}
// vector<pii> b(n);
// vector<pii> d(n);
// forr(i, n) {
//   b[i] = { a[i], c[i] };
//   d[i] = { c[i], a[i] };
// }
// sort(allEle(b));
// sort(allEle(d));
// h -= maxHit;
// int ans = 1;
// if (h <= 0) {
//   cout << 1 << endl;
//   return;
// }



signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}