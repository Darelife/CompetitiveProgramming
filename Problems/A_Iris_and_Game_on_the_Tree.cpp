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

struct node {
  int a;
  string s;
};

void solve() {
  /*
    ?I checked all the 3 hints,
    TODO <revisit>
    *Okay so, we'll compress the strings....that will be important
    *Eg: if the string is 1011101011, we'll write it as 1010101
    *In this, negedge will lead to an increase in the score, and the reverse
    *for posedge.
    *So, if the first and last bit are same,
    *(a[0]-'0')^(a[a.size()-1]-'0') == 0, the answer will be 0
    * and if they are different, then, the score will increase,
    * as the answer != 0
    *
    * We'll first count the freq of all the values of all the leafnodes
    * Now, as we can see, only 2 things matter. The value of the root,
    * and the values of the leaf nodes.
    *
    * Case 1: Root = 0
    * Then, (1) will try to make all the values of the leaf nodes, 1.
    * So, the score will be leaf(1) + ciel(leaf(?)/2)
    *
    * Case 2: Root = 1
    * (1) will try to make all the leaf nodes as 0
    * score = leaf(0) + ciel(leaf(?)/2)
    *
    * Case 3: Root = ?
    * Case 3.1: leaf(0) < leaf(1) : score = leaf(1) + ciel((leaf(?)-1)/2)
    * Case 3.2: leaf(0) > leaf(1) : score = leaf(0) + ciel((leaf(?)-1)/2)
    * Case 3.3: leaf(0) == leaf(1): score = leaf(0) + ciel(((leaf(?)-1)+nonLeaf(?)%2)/2)
    * This is because, in cases 3.3, we'll have to waste time, by filling all the
    * remaining nodes, as the person who fills the root first, will lose
  */

  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> deg(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    deg[a]++;
    deg[b]++;
    adj[a].pba(b);
    adj[b].pba(a);
  }
  string s;
  cin >> s;
  int zero = 0, one = 0, que = 0, nque = 0;
  //* ignore the root in this count...we've been told that 1 isn't a leaf
  for (int i = 1; i < n; i++) {
    if (deg[i] == 1 && s[i] == '1') one++;
    else if (deg[i] == 1 && s[i] == '0') zero++;
    else if (deg[i] == 1) que++;
    else if (s[i] == '?') nque ^= 1;
  }

  if (s[0] == '0') {
    cout << one + (que + 1) / 2 << endl;
  } else if (s[0] == '1') {
    cout << zero + (que + 1) / 2 << endl;
  } else {
    if (zero < one) {
      cout << one + que / 2 << endl;
    } else if (one < zero) {
      cout << zero + que / 2 << endl;
    } else {
      // if (n == 6)
        // debug(nque, que, zero);
      cout << zero + (nque + que) / 2 << endl;
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}