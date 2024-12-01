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

vector<int> primes;

void SieveOfEratosthenes(int n)
{
  // Create a boolean array "prime[0..n]" and initialize
  // all entries it as true. A value in prime[i] will
  // finally be false if i is Not a prime, else true.
  vector<bool> prime(n + 1, true);

  for (int p = 2; p * p <= n; p++) {


    // If prime[p] is not changed, then it is a prime
    if (prime[p] == true) {
      // Update all multiples of p greater than or
      // equal to the square of it numbers which are
      // multiple of p and are less than p^2 are
      // already been marked.
      for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }

  // // Print all prime numbers
  for (int p = 2; p <= n; p++)
    if (prime[p]) primes.pba(p);
}

void solve() {
  int n, m;
  cin >> n >> m;
  int k = 0;
  if (m > n * (n - 1) / 2) {
    cout << "-1\n";
    return;
  }
  if (m < n) {
    vint a(n, 2);
    for (int i = 1; i <= m; i++) {
      a[i] = 3;
    }
    for (int i = m + 1; i < n; i++) {
      a[i] = 6;
    }

    vpin(a);
    return;
  }
  int t = -1;
  for (int i = 1; i <= n; i++) {
    if (i * (i - 1) / 2 <= m) {
      t = i;
    } else break;
  }
  // if (n * (n - 1) / 2 == m) {
  //   t++;
  // }
  vint a(n);
  for (int i = 0; i < t; i++) {
    // put the primes
    a[i] = primes[i];
  }
  debug(a, t);
  m -= t * (t - 1) / 2;

  // int c = m / (t - 1);

  int tt = 1;
  for (int i = 0; i < t - m; i++) {
    tt *= primes[i];
  }
  a[t] = tt;
  debug(a, tt, m);
  int ttt = 1;
  for (int i = 0; i < t; i++) {
    ttt *= primes[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      a[i] = ttt;
    }
  }
  vpin(a);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  SieveOfEratosthenes(5000000);
  for (int i = 0; i < t; i++)
    solve();
}