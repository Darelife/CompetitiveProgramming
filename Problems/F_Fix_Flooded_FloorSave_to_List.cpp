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
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    a[i] = (x == '#') ? 1 : 0;
  }
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    b[i] = (x == '#') ? 1 : 0;
  }
  int multiple = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (i < n - 1 && a[i] == a[i + 1] && a[i] == 0) {
        a[i] = 1;
        a[i + 1] = 1;
      } else if (i < n - 1 && b[i] == b[i + 1] && b[i] == 0) {
        b[i] = 1;
        b[i + 1] = 1;
      } else {
        cout << "None" << endl;
        return;
      }
    } else if (a[i] == 0 && b[i] == 0) {
      if (i < n - 1 && a[i] == a[i + 1] && b[i] == b[i + 1]) {
        multiple = 1;
        a[i] = 1;
        a[i + 1] = 1;
        b[i] = 1;
        b[i + 1] = 1;
      } else {
        a[i] = 1;
        b[i] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 || b[i] == 0) {
      cout << "None" << endl;
      return;
    }
  }
  if (multiple) {
    cout << "Multiple" << endl;
    return;
  }
  cout << "Unique" << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}