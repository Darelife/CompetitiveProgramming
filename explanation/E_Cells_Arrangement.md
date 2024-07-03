# Question Explanation
Basically in this question, we get a square matrix of size `n x n`.
- Now, we have a value `H`, which is `|x1-x2| + |y1-y2|` (Manhattan distance)
- We have to place `n` cells in the matrix, such that the vector of all the values of `H` from all the different combinations contains all the numbers from `0` to `x`....We have to maximize the value of `x`

(I'm gonna represent the points as X, and the remaining cells as O)
(Also, `n >= 2`)
(We have to output the indexes of the cells, where we place the X's)

# Case 1 : n = 2
```
X O
X O
```
- Vector of H = `{(|0-0| + |0-0|), (|0-0| + |0+1|), (|0-0| + |1-0), (|1-1| + |1-1|)}` = `{0,1,1,0}` => `{0,1}` 
- x = 1

# Case 2 : n = 3
```
X O O
X O X
O O O
```
- Vector of H => `{0,0,0,1,2,3}` => `{0,1,2,3}`
- x = 3
  
# Case 3 : n >= 4

Example : n = 5
```
X O O O O
X O O O O
O O X O O
O O O X O
O O O O X
```
- Vector of H => `{0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,4,4,4,5}` => `{0,1,2,3,4,5}`
- x = 5

We have to follow this pattern

# Solve Function
```cpp
void solve() {
  int n;
  cin >> n;
  if (n == 1) cout << "1 1" << endl;
  else if (n == 2) cout << "1 1\n2 1" << endl;
  else if (n == 3) cout << "1 1\n1 3\n2 1" << endl;
  else {
    cout << "1 1\n2 1" << endl;
    for (int i = 2; i < n; i++) {
      cout << i + 1 << " " << i + 1 << endl;
    }
  }
  cout << endl;
}
```

# The entire code
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  if (n == 1) cout << "1 1" << endl;
  else if (n == 2) cout << "1 1\n2 1" << endl;
  else if (n == 3) cout << "1 1\n1 3\n2 1" << endl;
  else {
    cout << "1 1\n2 1" << endl;
    for (int i = 2; i < n; i++) {
      cout << i + 1 << " " << i + 1 << endl;
    }
  }
  cout << endl;
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