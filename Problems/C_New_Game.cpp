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

// void solve() {
  // int n, k;
  // cin >> n >> k;

  // map<int, int> mp;
  // int lar = 0;
  // forr(i, n) {
  //   int x;
  //   cin >> x;
  //   mp[x]++;
  //   lar = max(lar, x);
  // }
  // int ans = 0;
  // // for (int i = 0; i <= lar; i++) {
  // //   if (mp[i] == 0) continue;
  // //   int tempAns = 0;
  // //   for (int j = i; j < i + k; j++) {
  // //     if (mp[j] == 0) {
  // //       ans = max(ans, tempAns);
  // //       break;
  // //     }
  // //     if (j > lar) {
  // //       // tempAns += mp[j];
  // //       ans = max(tempAns, ans);
  // //       break;
  // //     }
  // //     tempAns += mp[j];
  // //     ans = max(tempAns, ans);
  // //   }
  // // }

  // // 2 pointers
  // // go from 0 to lar inclusive
  // // select the last k elements only -> if i<k -> select the first i elements
  // // if any of the elements
  // int tempAns = 0;
  // int a = 0;
  // for (int i = 0; i <= lar; i++) {
  //   if (mp[i] == 0) {
  //     ans = max(tempAns, ans);
  //     // cout << "i: " << i << " ans: " << ans << endl;
  //     tempAns = 0;
  //     a = i + 1;
  //   } else {
  //     // cout << "i: " << i;
  //     if (i - a < k) {
  //       tempAns += mp[i];
  //       // cout << "k" << endl;
  //     } else {
  //       tempAns += mp[i];
  //       tempAns -= mp[a];
  //       a++;
  //       // cout << "l" << endl;
  //     }
  //     ans = max(ans, tempAns);
  //     // cout << "i: " << i << " ans: " << ans << endl;
  //   }

  // }
  // // debug(mp);
  // ans = max(tempAns, ans);
  // cout << ans << endl;
// }

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int, int> mp;
  vector<pii> v;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }

  int sum = 0;
  for (auto it : mp)
  {
    sum += it.second;
    v.pba({ it.first,sum });
  }

  // int lar = *max_element(a.begin(), a.end());
  // int ans = 0;
  // int tempAns = 0;
  // int start = 0; // Fix: Rename variable to avoid shadowing

  // for (int i = 0; i <= lar; i++) {
  //   while (mp[i] != 0 && i - start < k) {
  //     tempAns += mp[i];
  //     start++;
  //     i++;
  //   }
  //   ans = max(tempAns, ans);
  //   if (mp[i] == 0) {
  //     tempAns = 0;
  //     start = i + 1;
  //   }
  //   else {
  //     tempAns -= mp[start];
  //     start++;
  //   }
  // }
  // ans = max(tempAns, ans);
  // cout << ans << endl;

  int i = 0;
  // int ans = 0;
  int ans = v[i].second;
  for (int j = 1; j < v.size(); j++) {
    // check if v[i] and v[j] have a difference of 1 or not -> mod -> nvm, they are sorted, cuz of the map
    // check if the difference between the two is greater than k -> while it's yes, keep incrementing i
    // since we are using the prefixSum, ans = max(ans, v[j].second - v[i-1].second), because it's inclusive
    // if i == 0, then ans = max(ans, v[j].second) though

    if (v[j - 1].first + 1 != v[j].first) {
      i = j;
      if (j == 0) {
        ans = max(ans, v[j].second);
      }
      else {
        ans = max(ans, v[j].second - v[i - 1].second);
      }
    }
    while (v[j].first - v[i].first >= k) {
      i++;
    }

    int tempAns = v[j].second;
    if (i > 0) {
      tempAns -= v[i - 1].second;
    }
    ans = max(ans, tempAns);

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