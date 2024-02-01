#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define la(i, n) for (int i = 0; i < n; i++)  // loop around
#define ela(i, n) for (int i = 0; i < n; i++) // Equal Loop Around
#define pba push_back
#define pfa push_front
#define popb pop_back
#define popf pop_front
#define gla(i, a, n) for (int i = a; i < n; i++) // general loop around
#define empb emplace_back
#define empf emplace_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()
#define sq(x) ((x) * (x))
#define lasqr(i, n) for (int i = 0; i * i < n; i++) // loop around square root
#define mpair make_pair
#define mtuple make_tuple

typedef vector<int> vint;
typedef vector<ll> vill;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void solve() {
  // int n;
  // cin >> n;
  // vector<int> a(n);
  // for (auto &i : a)
  //   cin >> i;
  // vector<int> sn(n);
  // string s = "";
  // cin >> s;
  // la(i, n) { sn[i] = s[i] - '0'; }

  int n;
  cin >> n;
  vector<vector<ll>> v(n + 1, vector<ll>());
  vector<int> u(n), s(n);
  for (auto &x : u)
    cin >> x;
  for (auto &x : s)
  
    cin >> x;

  for (int i = 0; i < n; i++) {
    v[u[i]].push_back(s[i]);
  }

  vector<ll> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    vector<ll> temp(1);
    sort(v[i].begin(), v[i].end(), greater<ll>());
    for (int j = 0; j < v[i].size(); j++) {
      temp.push_back(temp.back() + v[i][j]);
    }
    for (int j = 1; j <= temp.size(); j++) {
      int t = (int)(temp.size() - 1) / j;
      t = t * j;

      ans[j] += temp[t];
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? "\n" : " ");
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