#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define f(i, a, b) for (int i = a; i < b; i++)
#define pba push_back

typedef vector<int> vint;
#define vcin(vint, n) f(i, 0, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;

#define endl '\n'
const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

bool check(const vector<int>& arr, int D, int mid) {
  int cnt = 0;
  for (int num : arr) {
    if (num >= mid)
      cnt++;
    else
      cnt = 0;
    if (cnt >= D)
      return true;
  }
  return false;
}

void solve() {
  int n, d;
  cin >> n >> d;
  vint a(n);
  vcin(a, n);
  int maxx = *max_element(a.begin(), a.end());
  int l = 0, r = maxx, x = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(a, d, mid)) {
      x = mid, l = mid + 1;
    } else  r = mid - 1;
  }
  cout << x << " ";


  vint pre(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + a[i];
  }

  vint valid(n, 0);
  for (int i = 0; i < n; i++) {
    valid[i] = (a[i] >= x) ? 1 : 0;
  }

  vint preValid(n + 1, 0);
  for (int i = 0; i < n; i++) {
    preValid[i + 1] = preValid[i] + valid[i];
  }

  double ans = 0.0;
  for (int i = 0; i <= n - d; i++) {
    if (preValid[i + d] - preValid[i] == d) {
      double avg = double(pre[i + d] - pre[i]) / d;
      if (avg > ans) {
        ans = avg;
      }
    }
  }

  cout << fixed << setprecision(6) << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}