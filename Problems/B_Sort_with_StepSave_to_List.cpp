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
  int n, k;
  cin >> n >> k;
  // if (k == 1) {
  //   cout << 0 << endl;
  //   return;
  // }

  vint a(n);
  vcin(a, n);
  // vint b = a;
  // sort(b.begin(), b.end());
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] - 1) % k != i % k) cnt++;
  }
  // map<int, int> ind;
  // for (int i = 0; i < n; i++) ind[a[i]] = i;
  // int cnt = 0;
  // for (int i = 0; i < n; i++) {
  //   // if ((abs(ind[b[i]] - i)) % k) cnt++;
  //   if ()
  // }
  if (cnt == 0) {
    cout << 0 << endl;
  } else if (cnt == 2) cout << 1 << endl;
  else cout << -1 << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}