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
  vint a(n);
  vcin(a, n);
  int num = a[0] * n - a[n - 1], den = n * n - 1;

  if (num % den != 0) {
    cout << "NO" << endl;
    return;
  }

  int q = num / den;
  int p = a[0] - q * n;

  if (p < 0 || q < 0) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] != p * (i + 1) + q * (n - i)) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}