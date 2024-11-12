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

// the prime things is from geek for geeks
const int MAXN = 1e6 + 1;
int prime[MAXN];
int primeCount[MAXN];

void isPrime(int n) {
  fill(prime, prime + n + 1, 1); // Initialize all entries as prime
  prime[0] = prime[1] = 0; // 0 and 1 are not prime numbers

  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == 1) {
      for (int i = p * p; i <= n; i += p) {
        prime[i] = 0; // Mark all multiples of p as not prime
      }
    }
  }

  // Compute the cumulative count of primes
  primeCount[0] = primeCount[1] = 0;
  for (int i = 2; i <= n; i++) {
    primeCount[i] = primeCount[i - 1] + prime[i];
  }
}
void solve() {
  // if n, and n*n (n^2) are in the array, n and n*n (n^2) aren't lonely.
  // 
  int t;
  cin >> t;
  isPrime(1e6);
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    int ans = 1; // 1 will always be lonely
    // for (int i = sqrt(n) + 1;i <= n;i++) {
    //   // cout << i << endl;
    //   if (prime[i]) {
    //     // cout << i << "prime" << endl;
    //     ans++;
    //   }
    // }
    int a = sqrt(n);
    ans += primeCount[n] - primeCount[a];
    cout << ans << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}