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
  cin >> n;
  vint a(n), b(n);
  vcin(a, n);
  vcin(b, n);
  int ans = 0;

  // vint aa(n + 1), bb(n + 1);
  vint c(n + 1);

  if (a[n - 1] == b[n - 1]) {
    cout << n << endl;
    return;
  }

  for (int i = n - 2; i >= 0; i--) {
    // if (a[i] == b[i] || (i > 0 && a[i] == a[i - 1]) || (i > 1 && a[i] == a[i - 2]) || (aa[b[i]] % 2 == i % 2) || (bb[a[i] % 2 != i % 2])) {
    if (a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || (c[a[i]] || c[b[i]])) {
      cout << i + 1 << endl;
      return;
    }
    c[a[i + 1]]++, c[b[i + 1]]++;
    // aa[a[i]] = i;
    // bb[b[i]] = i;
  }
  // int stuff = (aa[b[0]] % 2 == 0) || (bb[a[0] % 2 != 0]);
  // if (a[0] == b[0] || stuff) {
  //   cout << 1 << endl;
  // }
  cout << 0 << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}