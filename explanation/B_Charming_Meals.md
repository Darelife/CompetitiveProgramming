# Question Explanation
- In this q, we get 2 array's of `n` elements -> a,b
- We have to make pairs of a[i], and b[j] such that the minimum value of |a[i] - b[j]| for all `i` and `j` is maximized
- i and j belong from 0 to n-1

# Explanation
- We have to sort both the arrays
- Our solution will be O(n^2)
- Basically now, we'll go for every `i` from `0` to `n-1`
- We'll create a `minn` variable, and initialize it with `INT_MAX`
- Now, we'll go for every `j` from `0` to `n-1`
- Now basically, we'll try to alternate it...if `j<=i`, we'll take the abs of the difference between `a[j]` and `b[n+j-i-1]` (ie. the value of `b` from `i+1` to `n-1`)
- And, if `j>i`, we'll take the abs of the difference between `a[j]` and `b[j-i-1]` (ie. the value of `b` from `0` to `i-1`)

# Code (Important Part in C++) 
```cpp
int ans = 0;
forr(i, n) {
  int minn = inf;
  forr(j, n) {
    // if (j == i) continue;
    if (j <= i) minn = min(minn, abs(a[j] - b[n + j - i - 1]));
    else minn = min(minn, a[j] - abs(b[j - i - 1]));
  }
  ans = max(ans, minn);
}
```

# Code (Full)
```cpp
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
  int n;
  cin >> n;
  vint a(n);
  vint b(n);
  vcin(a, n);
  vcin(b, n);
  sort(allEle(a));
  sort(allEle(b));

  int ans = 0;
  forr(i, n) {
    int minn = inf;
    forr(j, n) {
      // if (j == i) continue;
      if (j <= i) minn = min(minn, abs(a[j] - b[n + j - i - 1]));
      else minn = min(minn, a[j] - abs(b[j - i - 1]));
    }
    ans = max(ans, minn);
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
```