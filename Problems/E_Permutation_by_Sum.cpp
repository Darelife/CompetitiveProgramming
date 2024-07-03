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

int possible(int len, int s, int n) {
  int maxx = 0, minn = 0, a = n, b = 1;
  for (int i = 0; i < len; i++) {
    maxx += a;
    minn += b;
    a--, b++;
  }
  return s >= minn && s <= maxx;
}
void solve() {
  int n, l, r, s;
  cin >> n >> l >> r >> s;
  int len = r - l + 1;
  r--, l--;
  int minn = (len * (len + 1)) / 2; // sigma len
  int maxx = (2 * n - len + 1) * len / 2; // sigma n - sigma(n-len)
  if (s < minn || s > maxx) {
    cout << -1 << endl;
    return;
  }

  int difference = maxx - s;
  // place the maximum elements first
  vint ans;
  vint solution;
  // for (int i = n; i > n - len; i--) {
  //   if (difference >= i - len) {
  //     solution[n - i] = i;
  //     difference -= i - len;
  //     nums[i - 1] = 0;
  //   } else {
  //     solution[n - i] = i - difference;
  //     // debug(nums);
  //     nums[i - difference - 1] = 0;
  //     difference = 0;
  //     // debug(nums[i - difference - 1]);
  //   }
  // }
  for (int i = n; i >= 1; i--) {
    if (s - i >= 0 && possible(len - 1, s - i, i - 1)) {
      s -= i;
      len--;
      solution.pba(i);
    }
    if (s == 0) break;
  }
  if (s != 0) {
    cout << -1 << endl;
    return;
  }

  debug(solution);
  sort(allEle(solution));
  vint nums(n - len);
  // put all numbers from 1 to n, which aren't in the sorted solution, in nums
  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (j < solution.size() && i == solution[j]) {
      j++;
    } else {
      nums[i - j - 1] = i;
    }
  }
  debug(nums);
  for (int i = 0; i < l; i++) {
    ans.pba(nums[i]);
  }
  for (int i = 0; i < solution.size(); i++) {
    ans.pba(solution[i]);
  }
  for (int i = r + 1; i < n; i++) {
    ans.pba(nums[i - r - 1 + l]);
  }
  vpin(ans);
  // 
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}