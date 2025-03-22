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

void smallestPrimefactor(vint& spf, int psize) {
  vint tspf(psize + 1, 1e9);
  tspf[0] = 0;
  tspf[1] = 1;
  vector<bool> isprime(psize + 1, true);
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 2;i <= psize;i++)
  {
    if (isprime[i])
    {
      tspf[i] = i;
      for (int j = i * i;j <= psize;j = j + i)
      {
        isprime[j] = false;
        tspf[j] = min(i, tspf[j]);
      }
    }
  }
  spf = tspf;
}

vector<pair<int, int>> primeFactorization(int x, vector<int>& spf) {
  vector<pair<int, int>> ans;
  while (x != 1)
  {
    int prime = spf[x];
    int cnt = 0;
    while (x % prime == 0)
    {
      cnt++;
      x = x / prime;
    }
    ans.push_back({ prime,cnt });
  }
  return ans;
}

void precomputeprime(vector<bool>& primes, int psize) {
  vector<bool> tvector(psize + 1, true);
  tvector[0] = false;
  tvector[1] = false;
  for (int i = 2;i <= psize;i++)
  {
    if (tvector[i] == true)
    {
      for (int j = i * i;j <= psize;j = j + i)
      {
        tvector[j] = false;
      }
    }
  }
  primes = tvector;
}

int mul(int x, int y, int MOD) {
  return (x % MOD * y % MOD) % MOD;
}

int binpowmod(int x, int y, int mod)
{
  int ans = 1;
  while (y > 0)
  {
    if (y & 1)
    {
      ans = mul(ans, x, mod);
    }
    x = mul(x, x, mod);
    y = y >> 1;
  }
  return ans;
}

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

int modDivide(int x, int y, int mod) // (a/(b*c))%m = (a. b^(m-2) . c^(m-2))%m  ..IF M is not PRIME -> (a/b)%M = (a * (b^(phi(M) - 1)))%M.
{
  return mul(x, binpowmod(y, (mod - 2), mod), mod);
}

int ncr(int n, int r, vint& fact, vint& ifact, int mod = 1e9 + 7)
{
  return mul(fact[n], mul(ifact[r], ifact[n - r], mod), mod); // MOD = 1e9+7 ;
}

int dpCache[20][110][170][2];
int dpVisited[20][110][170][2];
int dp[20][110][170][2];
int currDPId = 1;

int cm;
int cp;
vector<int> curA;
int plzwork(int p = 0, int i = 0, int j = 0, int k = 0) {
  if (p == cp) {
    int flag = k;
    int c = j;
    while (c > 0) {
      if (c % 10 == 7) flag = 1;
      c /= 10;
    }
    return ((i == cm) && (flag == 1)) ? 1 : 0;
  }

  if (dpVisited[p][i][j][k] == currDPId) {
    return dpCache[p][i][j][k];
  }

  dpVisited[p][i][j][k] = currDPId;
  int res = 0;

  if (p == 0) {
    int sum = curA[0] + j;
    int d = sum % 10;
    int newj = sum / 10;
    int newk = k || (d == 7);
    res = plzwork(p + 1, i, newj, newk ? 1 : 0);
  } else {
    int rem = cm - i;
    for (int a = 0; a <= rem; a++) {
      int sum = curA[p] + a + j;
      int d = sum % 10;
      int newj = sum / 10;
      int newk = k || (d == 7);
      if (plzwork(p + 1, i + a, newj, newk ? 1 : 0)) {
        res = 1;
        break;
      }
    }
  }

  dpCache[p][i][j][k] = res;
  return res;
}

bool contains7(long long x) {
  if (x == 0) return false;
  while (x > 0) {
    if (x % 10 == 7)
      return true;
    x /= 10;
  }
  return false;
}

void solve() {
  long long n;
  cin >> n;

  if (contains7(n)) {
    cout << 0 << endl;
    return;
  }

  int mUpper = 0;
  while (true) {
    if (contains7(n + 9LL * mUpper))
      break;
    mUpper++;
  }

  int ans = mUpper;

  for (int m = 1; m <= mUpper; m++) {
    if (m > n) continue;
    cm = m;
    cp = 11;
    curA.assign(cp, 0);

    long long A_val = n - m;
    for (int i = 0; i < cp; i++) {
      curA[i] = A_val % 10;
      A_val /= 10;
    }

    currDPId++;
    int psible = plzwork();
    if (psible) {
      ans = m;
      break;
    }
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