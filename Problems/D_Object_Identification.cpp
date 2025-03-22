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

// #define endl '\n'
const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

int ask(int x, int y) {
  cout << "? " << x << ' ' << y << endl;
  int d; cin >> d;
  return d;
}

void solve() {
  int n;
  cin >> n;
  vint a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vint cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
  }
  int x = -1, y = -1;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) x = i;
    else y = i;
  }
  if (x != -1) {
    int d1 = ask(x, y);
    int d2 = ask(y, x);
    if (d1 && d2) {
      cout << "! B" << endl;
    } else {
      cout << "! A" << endl;
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1)x = i;
      if (a[i] == n)y = i;
    }
    int d1 = ask(x, y);
    int d2 = ask(y, x);
    if (d1 == d2 && d1 >= n - 1 && d2 >= n - 1) {
      cout << "! B" << endl;
    } else {
      cout << "! A" << endl;
    }
  }
  return;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}