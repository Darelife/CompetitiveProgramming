#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a)                                                              \
  cout << #a << " = ";                                                         \
  for (auto x : a)                                                             \
    cout << x << " ";                                                          \
  cout << "\n";

#define f(i, a, b) for (int i = a; i < b; i++)
#define pba push_back

typedef vector<int> vint;
#define vcin(vint, n) f(i, 0, n) cin >> vint[i]
#define vpin(vint)                                                             \
  for (auto x : vint)                                                          \
    cout << x << " ";                                                          \
  cout << endl;

#define endl '\n'
const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

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
typedef tree<int, null_type, less<int>, rb_tree_tag,
  tree_order_statistics_node_update>
  pbds;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

void smallestPrimefactor(vint& spf, int psize) {
  vint tspf(psize + 1, 1e9);
  tspf[0] = 0;
  tspf[1] = 1;
  vector<bool> isprime(psize + 1, true);
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 2; i <= psize; i++) {
    if (isprime[i]) {
      tspf[i] = i;
      for (int j = i * i; j <= psize; j = j + i) {
        isprime[j] = false;
        tspf[j] = min(i, tspf[j]);
      }
    }
  }
  spf = tspf;
}

vector<pair<int, int>> primeFactorization(int x, vector<int>& spf) {
  vector<pair<int, int>> ans;
  while (x != 1) {
    int prime = spf[x];
    int cnt = 0;
    while (x % prime == 0) {
      cnt++;
      x = x / prime;
    }
    ans.push_back({ prime, cnt });
  }
  return ans;
}

void precomputeprime(vector<bool>& primes, int psize) {
  vector<bool> tvector(psize + 1, true);
  tvector[0] = false;
  tvector[1] = false;
  for (int i = 2; i <= psize; i++) {
    if (tvector[i] == true) {
      for (int j = i * i; j <= psize; j = j + i) {
        tvector[j] = false;
      }
    }
  }
  primes = tvector;
}

int mul(int x, int y, int MOD) { return (x % MOD * y % MOD) % MOD; }

int binpowmod(int x, int y, int mod) {
  int ans = 1;
  while (y > 0) {
    if (y & 1) {
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

int modDivide(int x, int y,
  int mod) // (a/(b*c))%m = (a. b^(m-2) . c^(m-2))%m  ..IF M is not
  // PRIME -> (a/b)%M = (a * (b^(phi(M) - 1)))%M.
{
  return mul(x, binpowmod(y, (mod - 2), mod), mod);
}

int ncr(int n, int r, vint& fact, vint& ifact, int mod = 1e9 + 7) {
  return mul(fact[n], mul(ifact[r], ifact[n - r], mod), mod); // MOD = 1e9+7 ;
}

class DSU {
public:
  vector<int> parent;
  vector<int> size;

  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b])
        swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
};

vint a(150000);       // 0 based
vint seg(4 * 150000); // 1 based

void build(int s, int e, int index) { // O(N)
  // leaf node
  if (s == e) {
    seg[index] = a[s];
    return;
  }
  int mid = s + (e - s) / 2;
  build(s, mid, 2 * index);
  build(mid + 1, e, 2 * index + 1);
  seg[index] = seg[2 * index] + seg[2 * index + 1];
}

void update(int s, int e, int index, int updateIndex,
  int updateValue) { // O(logN)
  // leaf node
  if (s == e) {
    seg[index] = updateValue;
    return;
  }
  int mid = s + (e - s) / 2;
  if (mid >= updateIndex) {
    update(s, mid, 2 * index, updateIndex, updateValue);
  } else {
    update(mid + 1, e, 2 * index + 1, updateIndex, updateValue);
  }
  seg[index] = seg[2 * index] + seg[2 * index + 1];
}

int query(int s, int e, int index, int l, int r) { // O(logN)
  // no overlap
  if (s > r || e < l) {
    return 0;
  }
  // complete overlap
  if (s <= l && e >= r) {
    return seg[index];
  }
  // partial overlap
  int mid = s + (e - s) / 2;
  int leftAns = query(s, mid, 2 * index, l, r);
  int rightAns = query(mid + 1, e, 2 * index + 1, l, r);
  return leftAns + rightAns;
}

int knapsack(const vint& w, const vint& c, int capacity) {
  map<int, int> dp;
  dp[0] = 0;
  int n = w.size();
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> updates;
    for (auto& [curr_w, curr_c] : dp) {
      if (curr_w + w[i] <= capacity) {
        updates.push_back({ curr_w + w[i], curr_c + c[i] });
      }
    }
    for (auto& [new_w, new_c] : updates) {
      if (dp.count(new_w)) {
        dp[new_w] = max(dp[new_w], new_c);
      } else {
        dp[new_w] = new_c;
      }
    }
  }
  int ans = 0;
  for (auto& [weight, value] : dp) {
    ans = max(ans, value);
  }
  return ans;
}


void solve() {
  int n, w;
  cin >> n >> w;
  vector<int> ww(n), cc(n);
  for (int i = 0; i < n; i++) {
    cin >> ww[i] >> cc[i];
    ww[i] = binpow(2, ww[i]);
  }
  cout << knapsack(ww, cc, w) << endl;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}