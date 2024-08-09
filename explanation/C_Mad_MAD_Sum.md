# Question Explanation
Basically, u have an array of numbers...now, u have to go through the array, and while u are going through it, u keep a track of the largest number which appears more than once, and unless u come across another element which satisfies the same constraint, u keep updating ur element to the other element
For example,
[8,6,7,9,8,5,6,9,9,10,26,15,10] becomes
[0,0,0,0,8,8,8,8,9,9,9,9,10]
...now u keep doing this until all the elements are 0
[0,0,0,0,0,8,8,8,8,9,9,9,9]
[0,0,0,0,0,0,8,8,8,8,9,9,9]
[0,0,0,0,0,0,0,8,8,8,8,9,9]
[0,0,0,0,0,0,0,0,8,8,8,8,9]
[0,0,0,0,0,0,0,0,0,8,8,8,8]
[0,0,0,0,0,0,0,0,0,0,8,8,8]
[0,0,0,0,0,0,0,0,0,0,0,8,8]
[0,0,0,0,0,0,0,0,0,0,0,0,8]
[0,0,0,0,0,0,0,0,0,0,0,0,0]
and then in the end, u return the sum of all the elements (in all the arrays)

Eg: for 
[2,2,3] -> sum = 7
[0,2,2] -> sum = 7 + 4 = 11
[0,0,2] -> sum = 11 + 2 = 13
[0,0,0] -> sum = 13 + 0 = 13
It returns `13`

Similarly the first case returns `421`

# My Approach
We basically just have to do brute force
- Take the array elements (let's call the vector as `a`)
- Keep a track of the largest number which appears more than once, and its count (`largestNum` and `largestCount`)
- Create 2 maps, one for the count of the elements initially, and one for the count of the elements after 1 operation
- If u look at the first case i wrote above, u can see that the elements keep moving right until they reach the end, so basically, we can just count the number of times the number will stay in the array and multiply it with the element itself to get the number we need to add to the sum
- So, every element after the first 2 operations will come up `n-i-1` times, where `n` is the size of the array, and `i` is the index of the element
- So, we first get the sum after the first 2 operations manually
- After which, unless the element only comes up once after the second operation (we can check it using the 2nd map), we can add the `element * (n-i-1)` to the sum
- If the element only appears once, we also keep a track of the element which appears just before it, so, we do `lastElement * (n-i-1)` and add it to the sum
- In the end, we return the sum

# Complexity
- O(n) time

# Solve function
```cpp
void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  int largestCount = 0;
  int largestNum = 0;
  map<int, int> hash;
  map<int, int > hash2;
  vint b(n);
  int sum = 0;
  forr(i, n) {
    sum += a[i];
  }
  forr(i, n) {
    hash[a[i]]++;
    if (hash[a[i]] >= 2) {
      largestNum = max(largestNum, a[i]);
      // if (hash[a[i]] > largestCount) {
      //   largestCount = hash[a[i]];
      //   largestNum = a[i];
      // }
    }
    largestCount = max(largestCount, hash[a[i]]);
    hash2[largestNum]++;
    b[i] = largestNum;
    sum += b[i];
  }

  debug(b, sum);

  int aa = 0;
  forr(i, n) {
    if (hash2[b[i]] >= 2) {
      sum += (b[i] * (n - i - 1));
      aa = b[i];
    } else {
      sum += (aa * (n - i - 1));
    }
  }
  cout << sum << endl;
}
```

# The Imp Stuff of the code
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forr(i, n) for (int i = 0; i < n; i++)
typedef vector<int> vint;
#define vcin(vint, n) forr(i, n) cin >> vint[i]

void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  int largestCount = 0;
  int largestNum = 0;
  map<int, int> hash;
  map<int, int > hash2;
  vint b(n);
  int sum = 0;
  forr(i, n) {
    sum += a[i];
  }
  forr(i, n) {
    hash[a[i]]++;
    if (hash[a[i]] >= 2) {
      largestNum = max(largestNum, a[i]);
    }
    largestCount = max(largestCount, hash[a[i]]);
    hash2[largestNum]++;
    b[i] = largestNum;
    sum += b[i];
  }

  int aa = 0;
  forr(i, n) {
    if (hash2[b[i]] >= 2) {
      sum += (b[i] * (n - i - 1));
      aa = b[i];
    } else {
      sum += (aa * (n - i - 1));
    }
  }
  cout << sum << endl;
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

# The Entire Code
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

void __print(int x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const int inf = 1e9 + 5;

int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  int largestCount = 0;
  int largestNum = 0;
  map<int, int> hash;
  map<int, int > hash2;
  vint b(n);
  int sum = 0;
  forr(i, n) {
    sum += a[i];
  }
  forr(i, n) {
    hash[a[i]]++;
    if (hash[a[i]] >= 2) {
      largestNum = max(largestNum, a[i]);
      // if (hash[a[i]] > largestCount) {
      //   largestCount = hash[a[i]];
      //   largestNum = a[i];
      // }
    }
    largestCount = max(largestCount, hash[a[i]]);
    hash2[largestNum]++;
    b[i] = largestNum;
    sum += b[i];
  }

  debug(b, sum);

  int aa = 0;
  forr(i, n) {
    if (hash2[b[i]] >= 2) {
      sum += (b[i] * (n - i - 1));
      aa = b[i];
    } else {
      sum += (aa * (n - i - 1));
    }
  }
  cout << sum << endl;
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