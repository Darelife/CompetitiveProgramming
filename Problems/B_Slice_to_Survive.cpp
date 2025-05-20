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

void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int ans = INT_MAX;
  ans = min(ans, 1 + (int)ceil(log2(n)) + (int)ceil(log2(b)));
  ans = min(ans, 1 + (int)ceil(log2(n)) + (int)ceil(log2(m - b + 1)));
  ans = min(ans, 1 + (int)ceil(log2(m)) + (int)ceil(log2(a)));
  ans = min(ans, 1 + (int)ceil(log2(m)) + (int)ceil(log2(n - a + 1)));
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}