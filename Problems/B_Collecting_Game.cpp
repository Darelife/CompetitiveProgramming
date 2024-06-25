#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define int ll
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
  // vector<pair<int, int>> v(n);
  // vint vv;
  // la(i, n) {
  //   int a;
  //   cin >> a;
  //   cout << "one" << endl;
  //   v[i] = mpair(a, i);
  //   vv[i] = a;
  // }
  // cout << "rfj4ike" << endl;
  // sort(allEle(v));
  // cout << "jf4moel" << endl;
  // gla(i, 0, n) {
  //   int ans = 0;
  //   vector<pair<int, int>> b = v;
  //   gla(j, i + 1, n - i) {
  //     if (b[j].second <= b[i].second) {
  //       ans += b[j].first;
  //       b[j].first += b[i].second;
  //     } else
  //       break;
  //   }
  //   cout << ans << " ";
  // }
  // cout << endl;

  // int n;
  // cin >> n;
  // vector<pair<int, int>> v(n);
  // la(i, n) {
  //   int a;
  //   cin >> a;
  //   v[i] = mpair(a, i);
  // }
  // sort(allEle(v)); // sorts in descending order

  // vector<int> prefixSum(n, 0);
  // for (int i = 0; i < n; i++) {
  //   if (i == 0)
  //     prefixSum[i] = v[i].first;
  //   else
  //     prefixSum[i] = prefixSum[i - 1] + v[i].first;
  // }

  // for (int i = 0; i < n; i++) {
  //   int ans = 0;
  //   for (int j = 1; j < n; j++) {
  //     if (v[j].first <= prefixSum[i]) {
  //       ans++;
  //     } else {
  //       break;
  //     }
  //   }
  //   cout << ans << " ";
  // }
  // cout << endl;

  // // print every element in v
  // // la(i, n) { cout << v[i].first << " " << v[i].second << endl; }

  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<int> ps(n); // prefix sum
  vector<int> ans(n);
  la(i, n) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(allEle(v));
  ps[0] = v[0].first;
  gla(i, 1, n) ps[i] = ps[i - 1] + v[i].first;
  ans[v.back().second] = n - 1;
  int last = n - 1;
  for (int i = v.size() - 2; i >= 0; i--) {
    if (ps[i] < v[i + 1].first) {
      last = i;
    }
    ans[v[i].second] = last;
  }
  la(i, n) cout << ans[i] << " ";
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