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

bool check(int mid, int n, int k, const string& s, const vint& a) {
  int ops = 0, i = 0;
  while (i < n) {
    if (s[i] == 'B' && a[i] > mid) {
      ops++;
      while (i < n && (s[i] == 'B' || a[i] <= mid)) i++;
    }
    i++;
  }
  return ops <= k;
}

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vint a(n);
  for (int& x : a) cin >> x;

  int l = 0, r = *max_element(a.begin(), a.end()), ans = r;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid, n, k, s, a)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}