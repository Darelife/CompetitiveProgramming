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

const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  if (n == 1 && k == 1) {
    cout << 1 << endl << 1 << endl;
  } else if (k == 1 || k == n) cout << -1 << endl;
  else if (k % 2 == 1) cout << 3 << endl << 1 << " " << k - 1 << " " << k + 2 << endl;
  else cout << 3 << endl << 1 << " " << k << " " << k + 1 << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}