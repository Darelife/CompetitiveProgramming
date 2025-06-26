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
  int n;
  int k;
  cin >> n >> k;
  vector<int> a(n);
  vcin(a, n);
  int ans = 0;
  for (auto v : a) ans += __builtin_popcountll(v);

  vector<int> cost;
  for (auto v : a) {
    int cur = v;
    while (true) {
      int p = __builtin_ctzll(~cur);
      if (p >= 60) break;
      int c = 1LL << p;
      if (c > k) break;
      cost.pba(c);
      cur += c;
    }
  }

  sort(cost.begin(), cost.end());
  int used = 0;
  for (auto c : cost) {
    if (used + c > k) break;
    used += c;
    ans++;
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}