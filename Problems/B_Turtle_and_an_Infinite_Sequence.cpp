#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;

const int inf = 1e9 + 5;

void solve() {
  int n, m;
  cin >> n >> m;
  // int a1 = n + m;
  // int a2 = n - m;
  // int ans = 0;
  // if (n - m < 0) {
  //   for (int i = 0; i <= n + m; i++) {
  //     ans = ans | i;
  //   }
  // } else {
  //   for (int i = n - m; i <= n + m; i++) {
  //     ans = ans | i;
  //   }
  // }
  // cout << ans << endl;

  // todo: WE NEED TO FIND THE OR OF THE RANGE OF NUMBERS FROM n - m TO n + m

  // *ATTEMPT 1
  // for (int i = log10(n) + 1; i >= 0; i--) {
  //   if ((n - m) % (1 << i) != (n + m) % (1 << i)) {
  //     cout << (1 << (i + 1)) - 1 << endl;
  //     return;
  //   }
  // }

  // *ATTEMPT 2
  int ans = 0;
  int l = (n - m > 0) ? n - m : 0;
  for (int i = 0; i <= 32; i++) {
    // condition 1 -> length of the range of numbers from n - m to n + m is less than or equal to 2^i
    // this is because in binary, for each bit, the digit changes after 2^i numbers
    // if (((n + m) - l) + 1 <= 1 << i) {         //btw, 1<<i is 2^i


    if (((n + m) / (1 << i)) % 2 == 1) {
      // this makes sure that the ith bit of n+m is 1
      ans |= 1 << i;
      continue;
    }
    if (l == 0) {
      // this makes sure that the ith bit of the ans is 1, if l==0, and n+m >= 2^i
      if ((n + m) / (1 << i))
        ans |= 1 << i;
      continue;
    }
    // just as a backup,
    if (l / (1 << i) != (n + m) / (1 << i)) {
      ans |= 1 << i;
      // continue;
    }
    // }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}