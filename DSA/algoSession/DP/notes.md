# Dynamic Programming

## Q1
Given n, x.
N = Length of the string
X = Number of unique characters
How many such strings can we make??

### Solution
```cpp
int final_length = n, final_count = x;

int rec(int length, count) {
  if (length+1 == final_length) {
    if (count == final_count) {
      return count;
    }
    if (count + 1 == final_count) {
      return 26-count;
    }
    return 0;
  }
  int ans = count*num_of_strings(count, length+1);
  ans += (26-count)*num_of_strings(count+1, length+1);
  return ans;
}

int ans = rec(0,0);
```


```cpp
int rec(int length, int count, int final_length, int final_count) {
  if (length + 1 == final_length) {
    if (count == final_count) {
      return count;
    }
    if (count + 1 == final_count) {
      return 26 - count;
    }
    return 0;
  }
  int ans = count * rec(count, length + 1, final_length, final_count);
  ans += (26 - count) * rec(count + 1, length + 1, final_length, final_count);
  return ans;
}

void recTabulation(int n, int x) {
  vector<vector<int>> dp(n + 1, vector<int>(x + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      if (j > 0) {
        dp[i][j] = dp[i - 1][j - 1] * (26 - (j - 1));
      }
      dp[i][j] += dp[i - 1][j] * j;
      dp[i][j] %= MOD;
    }
  }
  cout << dp[n][x] << endl;
}


void solve() {
  int n, x;
  cin >> n >> x;
  recTabulation(n, x);
}
```



---------------------------------

## Q2 : Tower Of Hanoi
Step 1 : Move n-1 disks from A to C\
Step 2 : Move the last disk from A to B\
Step 3 : Move the n-1 disks from C to B

### Function
int move(number of elements to be moved, the tower from which we move, the tower to which we move, the extra tower)
move(n, a, b, c);

### Base Case 
if n == 1 -> move it from A to B

### Recursive Step
move(n, a, b, c) = move(n-1, a, c, b) + move(n-1, c, b, a);

### Code
```cpp
int ans = 0;
void solve(int n, char a, char b, char c) {
  if (n == 1) {
    cout << "Move 1 from " << a << " to " << b << endl;
    return;
  }
  solve(n - 1, a, c, b);
  cout << "Move " << n << " from " << a << " to " << b << endl;
  solve(n - 1, c, b, a);
  ans += 2;
}

signed main() {
  int n;
  cin >> n;
  solve(n, 'A', 'C', 'B');
  cout << ans + 1 << endl;
  return 0;
}
```


## Q3 : Counting Towers with L and straight Lines

## Q4 : Dice Combinations