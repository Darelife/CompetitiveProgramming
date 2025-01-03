#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define f(i, a, b) for (int i = a; i < b; i++)
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
template <typename T, typename V> void __print(const pair<T, V>& x) { cerr << '{';__print(x.first);cerr << ',';__print(x.second); cerr << '}'; }
template <typename T> void __print(const T& x) { int f = 0;cerr << '{';for (auto& i : x)cerr << (f++ ? "," : ""), __print(i);cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t);if (sizeof...(v)) cerr << ", ";_print(v...); }
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

// vint primes;
// vector<bool> isPrime;
// void sieve(int n) {
//   isPrime.assign(n + 1, true);
//   isPrime[0] = false;
//   isPrime[1] = false;
//   for (int i = 2; i <= n; i++) {

//   }
// }
vint spf;
void smallestPrimeFactor(int n) {
  vint a(n);
  for (int i = 0; i < n; i++) {
    a[i] = i;
  }

  for (int i = 2; i < n; i++) {
    if (a[i] == i) {
      for (int j = 2 * i; j < n; j += i) {
        a[j] = min(a[j], i);
      }
    }
  }
  spf = a;
}

vint primefactors(int x) {
  // vint ans;
  // for (int i = 2; i * i <= x; i++) {
  //   if (isPrime[i] && x % i == 0) {
  //     ans.pba(i);
  //   }
  //   if (isPrime[x / i] && x % (x / i) == 0) {
  //     ans.pba(x / i);
  //   }
  // }
  // if (x > 1) {
  //   ans.pba(x);
  // }
  // return ans;
  vint a = { spf[x] };
  while (x > 1) {
    if (a.back() != spf[x]) {
      a.pba(spf[x]);
    }
    x /= spf[x];
  }
  return a;
}

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << endl;
    return;
  }
  if (__gcd(a, b) != 1) {
    cout << 0 << endl;
    return;
  }
  if ((b - a) % 2 == 0) {
    if (b % 2) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return;
  }
  if (!(b - a - 1)) {
    cout << -1 << endl;
    return;
  }

  // int ans = 0;
  // for (int i = 0; i < 1e6; i++) {
  //   if (__gcd(a + i, b - a) == 1) {
  //     ans++;
  //   } else break;
  // }
  // cout << ans << endl;

  // now, b is odd and a is even or vice versa
  // gcd(a+k, b+k) = gcd(a+k, a+k-(b+k)) = gcd(a+k, a-b)

  vint divs;
  // for (int i = 1; i * i <= b - a; i++) {
  //   if ((b - a) % i == 0) {
  //     divs.pba(i);
  //     if (i != (b - a) / i) {
  //       divs.pba((b - a) / i);
  //     }
  //   }
  // }
  divs = primefactors(b - a);
  int temp = inf;
  // temp = (a + k)-a = k; in the end
  for (auto d : divs) {
    // just assuming that d is prime...if not, i don't think it will matter
    temp = min(temp, ((a + d - 1) / d) * d - a);
  }
  cout << temp << endl;


}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  smallestPrimeFactor(1e7 + 5);
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}