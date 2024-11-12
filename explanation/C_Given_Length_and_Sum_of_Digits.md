# Explanation
We basically receive 2 numbers
n = number of digits
sum = sum of digits

We need to find the smallest and largest number that can be formed with n digits and sum of digits as sum

We are gonna use the greedy approach to solve this problem

### For the smallest number
- We will start from the leftmost digit and fill it with the smallest possible digit which will still let (sum - new digit < remaining digits * 9)

```cpp
for (int i = 0; i < n; i++) {
  for (int j = 0; j < 10; j++) {
    if (i == 0 && j == 0) continue;
    if ((sum1 - j) <= (n - i - 1) * 9) {
      minn += (char)('0' + j);
      sum1 -= j;
      break;
    }
  }
}
```

### For the largest number
- Start with the left most digit
- Make it 9 as long as the sum is not less than 9
- If the sum is less than 9, then we will make the digit = sum
- If the sum is 0, then we will make the digit = 0

```cpp
for (int i = 0; i < n; i++) {
  if (sum <= 9) {
    maxx += (char)('0' + sum);
    sum = 0;
  } else {
    maxx += (char)('0' + 9);
    sum -= 9;
  }
}
```


### Overall Code

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
```

```cpp
void solve() {
  int n, sum;
  cin >> n >> sum;
  if (sum == 0) {
    if (n == 1) {
      cout << "0 0" << endl;
    } else {
      cout << "-1 -1" << endl;
    }
    return;
  }
  int sum1 = sum;
  int sum2 = sum;
  string minn = "", maxx = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == 0 && j == 0) continue;
      if ((sum1 - j) <= (n - i - 1) * 9) {
        minn += (char)('0' + j);
        sum1 -= j;
        // debug(minn);
        break;
      }
    }
  }
  // cout << minn << " ";
  for (int i = 0; i < n; i++) {
    if (sum <= 9) {
      maxx += (char)('0' + sum);
      sum = 0;
    } else {
      maxx += (char)('0' + 9);
      sum -= 9;
    }
  }
  // cout << sum << endl;
  // cout << 9 * n << endl;
  if (sum2 > 9 * n) {
    cout << "-1 -1" << endl;
  } else {
    cout << minn << " " << maxx << endl;
  }
}
```

```cpp
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}```
