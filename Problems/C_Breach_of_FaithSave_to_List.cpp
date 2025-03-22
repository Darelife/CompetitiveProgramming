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
  vint a(2 * n);
  vcin(a, 2 * n);

  vint ans(2 * n + 1, 0);
  sort(a.begin(), a.end());
  ans[0] = a[2 * n - 1];
  ans[1] = 0;

  // ans0 = final ans
  // ans1 = element to start with -> the missing element > ans[0] always
  // ans1 = sigma (largest - smallest) for all i = 1 to n
  // so, ans1 > ans0 always (!= because the answer must exist acc to the q)

  for (int i = 2 * n - 1; i >= n - 1; i--) ans[1] += a[i];
  for (int i = 0; i < n - 1; i++) ans[1] -= a[i];

  int top = 2 * n - 2;
  int bottom = 0;

  int i = 2;
  while (top > bottom) {
    ans[i] = a[top];
    ans[i + 1] = a[bottom];
    top--;
    bottom++;
    i += 2;
  }
  ans[2 * n] = a[top];

  vpin(ans);
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}