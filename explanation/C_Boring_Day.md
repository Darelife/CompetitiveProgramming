# Question Explanation
- In this q, we get `n` (number of cards), `l` (lower limit), `r` (upper limit). Now, we also get an array of `n` elements (numbers) -> cards -> have some number
- The person knows the order of all the cards, and everything...we have to greedily select `x` cards from the top, such that the sum of the cards is between `l` and `r` (both inclusive)....continuously...and find the maximum number of the set of cards we can select from the top of the deck

# Explanation
- We have to use a 2 pointer approach
- We will keep on adding the cards from the top, and if the sum of the cards is greater than `r`, we will remove the cards from the bottom
- If the sum of the cards is less than `l`, we will add the cards from the top
- We will keep on doing this until we reach the end of the array
- Everytime we get something in the range, we will update the answer, and move to the next set of cards

# Dry Run
- n = 5, l = 10, r = 20
- cards = [7, 9, 5, 19, 11]
- Now, we'll first select (7) -> sum = 7 < 10
- Then, we'll select (7. 9) -> sum = 16 (ans = 1)
- Now, we'll select (5) -> sum = 5 < 10
- Then, we'll select (5, 19) -> sum = 24 > 20 -> now, the answer is greater than the max limit
- So, we'll remove the cards from the bottom, and add the cards from the top
- So, selection = (19) -> sum = 19 (ans = 2)
- Now, we'll move to the next set again
- selection = (11) -> sum = 11 (ans = 3)
- So, the answer is 3

# Complexity
- O(n) time and O(1) space

# Code
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vint;

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vint cards(n);
  for (int i = 0; i < n; i++) {
    cin >> cards[i];
  }

  int ans = 0, sum = 0, p1 = 0;
  for (int p2 = 0; p2<n; p2++) {
    sum += cards[p2];
    while (sum > r && p1 <= p2) {
      sum -= cards[p1];
      p1++;
    }
    if (sum >= l && sum <= r) {
      ans++;
      sum = 0;
      p1 = p2+1;
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
```