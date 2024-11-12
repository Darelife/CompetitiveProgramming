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

vector<bool> is_prime(1e7);
vector<int> primes;
vector<int> primesBefore(1e7);
void sieve(int N) {
  is_prime.assign(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= N; ++i) {
    primesBefore[i] = primesBefore[i - 1] + is_prime[i];
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int count_subtractorizations(int N) {
  int count = 0;
  for (int p1 = 2; p1 <= N; p1++) {
    if (!is_prime[p1]) continue;
    for (int p2 = 2; p2 <= p1; p2++) {
      if (is_prime[p2] && is_prime[p1 - p2]) {
        count++;
        break; // Since we're only interested in counting unique subtractorizations
      }
    }
  }
  return count;
}

void solve() {
  int n;
  cin >> n;
  // int count = 0;
  // set<int> s;
  // // cout << 1 << endl;
  // if (n == 2 || n == 3 || n == 4) {
  //   cout << 0 << endl;
  //   return;
  // }
  // cout << max((long long)0, primesBefore[n] - 1) << endl;

  // basically the sum of 2 numbers will be prime.....okay im fucking up somewhere
  // a + b <= n;
  // a + b belong to prime
  // if any 'b' works for an 'a', move to the next 'a'
  int ans = 0;
  for (int a = 1; a <= n; a++) {
    if (is_prime[a])
      for (int b = a + 1;; b++) {
        if (a + b <= n) {
          if (is_prime[a] && is_prime[b] && is_prime[a + b]) {
            ans++;
            break;
          }
        } else break;
      }
  }
  cout << ans << endl;

}

signed main() {

#ifndef ONLINE_JUDGE 
  freopen("bval.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif 
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;

  vector<int> test_cases(t);
  int max_N = 0;

  for (int i = 0; i < t; i++) {
    cin >> test_cases[i];
    if (test_cases[i] > max_N) {
      max_N = test_cases[i]; // Track the largest N for efficient prime sieve
    }
  }

  sieve(max_N + 1);
  vector<int> subtractorizations(max_N + 1, 0);

  for (int p1 = 2; p1 <= max_N; p1++) {
    if (!is_prime[p1]) continue;  // Skip non-prime numbers
    for (int p2 = 2; p2 <= p1 / 2; p2++) {
      if (is_prime[p2] && is_prime[p1 - p2]) {
        subtractorizations[p1] = 1;  // Mark p1 as a valid subtractorization
        break;  // We only need one valid pair (p1, p2)
      }
    }
  }
  for (int i = 1; i <= max_N; i++) {
    subtractorizations[i] += subtractorizations[i - 1];
  }

  // Step 5: Output the result for each test case
  for (int i = 0; i < t; i++) {
    cout << "Case #" << i + 1 << ": " << subtractorizations[test_cases[i]] << endl;
  }
  // for (int i = 0; i < t; i++) {
  //   cout << "Case #" << i + 1 << ": ";
  //   solve();
  // }
  // for (int i = 0; i < t; i++) {
  //   int N = test_cases[i];
  //   int result = count_subtractorizations(N);
  //   cout << "Case #" << i + 1 << ": " << result << endl;
  // }
}