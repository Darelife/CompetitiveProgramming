// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// using pii = pair<int, int>;

// #define forr(i, n) for (int i = 0; i < n; i++)
// #define reforr(i, n) for (int i = n; i >= 0; i--)
// #define eqforr(i, a, n) for (int i = a; i <= n; i++)
// #define sqforr(i, n) for (int i = 1; i * i <= n; i++)
// #define genforr(i, a, b) for (int i = a; i < b; i++)
// #define pba push_back
// #define popb pop_back
// #define popf pop_front
// #define allEle(x) (x).begin(), (x).end()
// #define allRle(x) (x).rbegin(), (x).rend()

// typedef vector<int> vint;
// typedef vector<string> vstr;
// #define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
// #define vcin(vint, n) forr(i, n) cin >> vint[i]
// #define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
// #define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;

// void __print(int x) { cerr << x; }
// void __print(unsigned x) { cerr << x; }
// void __print(unsigned int x) { cerr << x; }
// void __print(float x) { cerr << x; }
// void __print(double x) { cerr << x; }
// void __print(long double x) { cerr << x; }
// void __print(char x) { cerr << '\'' << x << '\''; }
// void __print(const char* x) { cerr << '\"' << x << '\"'; }
// void __print(const string& x) { cerr << '\"' << x << '\"'; }
// void __print(bool x) { cerr << (x ? "true" : "false"); }
// template <typename T, typename V> void __print(const pair<T, V>& x) {
//   cerr << '{';
//   __print(x.first);
//   cerr << ',';
//   __print(x.second);
//   cerr << '}';
// }
// template <typename T> void __print(const T& x) {
//   int f = 0;
//   cerr << '{';
//   for (auto& i : x)
//     cerr << (f++ ? "," : ""), __print(i);
//   cerr << "}";
// }
// void _print() { cerr << "]\n"; }
// template <typename T, typename... V> void _print(T t, V... v) {
//   __print(t);
//   if (sizeof...(v))
//     cerr << ", ";
//   _print(v...);
// }
// #ifndef ONLINE_JUDGE
// #define debug(x...) cerr << "[" << #x << "] = [", _print(x)
// #else
// #define debug(x...)
// #endif

// const int inf = 1e9 + 5;

// int binpow(int a, int b) {
//   int res = 1;
//   while (b > 0) {
//     if (b & 1)
//       res = res * a;
//     a = a * a;
//     b >>= 1;
//   }
//   return res;
// }

// // // int sieve[inf];
// // vector<int> sieve(40001, 0);
// // vint primes;

// // void sieveFunc() {
// //   for (int i = 2;i < 40001;i++) {
// //     if (sieve[i] != 1) {
// //       primes.pba(i);
// //       for (int j = 2 * i; j < 40001; j += i)
// //         sieve[j] = 1;
// //     }
// //   }
// // }
// const int N = 40000;
// vector<int> primes;
// void sieveFunc() {
//   vector<bool> isPrime(N + 1, true);
//   isPrime[0] = false, isPrime[1] = false;
//   for (int i = 2; i * i <= N; i++)
//   {
//     if (!isPrime[i]) continue;
//     for (int j = i * i; j < N + 1; j += i) isPrime[j] = false;
//   }
//   for (int i = 0; i < N + 1; i++) {
//     if (isPrime[i]) primes.push_back(i);
//   }
// }

// // void solve() {
// //   int n; cin >> n; vint a(n); vcin(a, n);
// //   // set<int> s;

// //   // forr(i, n) {
// //   //   forr(j, primes.size()) {
// //   //     if (a[i] == 1) break; // if a[i] is 1 -> can't divide it further -> move to i+1
// //   //     if (a[i] % primes[j] == 0) {
// //   //       s.insert(primes[j]);
// //   //     }
// //   //   }
// //   // }
// //   map<int, int> mp;

// //   forr(i, n) {
// //     for (int p : primes) {
// //       if (a[i] % p) continue;
// //       if (mp[p]) {
// //         cout << "YES" << endl;
// //         return;
// //       } else {
// //         mp[p]++;
// //         while (a[i] % p == 0) a[i] /= p;
// //       }
// //     }
// //     if (a[i] > 1 && mp[a[i]] != 0) {
// //       cout << "YES" << endl; return;
// //     }
// //     mp[a[i]]++;
// //   }
// //   cout << "NO" << endl;
// // }


// inline void solve() {
//   int n; cin >> n;
//   vector<int> v(n);
//   map<int, int> mp;

//   for (auto& e : v) cin >> e;

//   for (int i = 0; i < n; i++) {
//     for (int p : primes) {
//       if (v[i] % p) continue;
//       if (mp[p]) {
//         cout << "YES" << endl;
//         return;
//       }
//       mp[p]++;
//       while ((v[i] % p) == 0) v[i] /= p;
//     }
//     if (v[i] > 1 && mp[v[i]]) {
//       cout << "YES" << endl;
//       return;
//     }
//     mp[v[i]]++;
//   }

//   cout << "NO" << endl;
// }


// signed main() {
//   // ios::sync_with_stdio(0);
//   // cin.tie(0);
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL); cout.tie(NULL);
//   cout << fixed << setprecision(9);

//   sieveFunc();
//   int t = 1;
//   cin >> t;
//   for (int i = 0; i < t; i++)
//     solve();
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int M = 1e9 + 7; //998244353;
const int INF = 2e18;

const int N = 40000;
vector<int> primes;
void sieve() {
  vector<bool> isPrime(N + 1, true);
  isPrime[0] = false, isPrime[1] = false;
  for (int i = 2; i * i <= N; i++)
  {
    if (!isPrime[i]) continue;
    for (int j = i * i; j < N + 1; j += i) isPrime[j] = false;
  }
  for (int i = 0; i < N + 1; i++) {
    if (isPrime[i]) primes.push_back(i);
  }
}

inline void solve() {
  int n; cin >> n;
  vector<int> v(n);
  map<int, int> mp;

  for (auto& e : v) cin >> e;

  for (int i = 0; i < n; i++) {
    for (int p : primes) {
      if (v[i] % p) continue;
      if (mp[p]) {
        cout << "YES" << endl;
        return;
      }
      mp[p]++;
      while ((v[i] % p) == 0) v[i] /= p;
    }
    if (v[i] > 1 && mp[v[i]]) {
      cout << "YES" << endl;
      return;
    }
    mp[v[i]]++;
  }

  cout << "NO" << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << fixed << setprecision(9);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  sieve();

  int tc = 1;
  cin >> tc;

  for (int i = 1; i < tc + 1; i++) {
    // cout<<"Case #"<<i<<": ";
    solve();
  }
  return !69;
}
// WHY DO WE FALL? 