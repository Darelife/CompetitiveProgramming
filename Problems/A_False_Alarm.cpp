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
  int n, x;
  cin >> n >> x;
  vint a(n);
  vcin(a, n);
  int fir = -1, la = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      fir = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      la = i;
      break;
    }
  }
  if (la == -1 || fir == -1) {
    if (x >= 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return;
  }
  if (la - fir + 1 > x) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}