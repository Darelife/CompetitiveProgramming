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
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);

  map<int, int> mp;
  for (auto i : a) mp[i]++;

  int ans = 0;
  int l = 0, r = 0, temp = 0;
  for (int i = 0; i < n; i++) {
    if (mp[a[i]] == 1) {
      temp++;
      if (temp > ans) {
        ans = temp;
        l = i - temp + 1;
        r = i;
      }
    } else {
      temp = 0;
    }
  }
  if (ans == 0) {
    cout << "0\n";
    return;
  }
  cout << l + 1 << " " << r + 1 << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}