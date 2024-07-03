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

void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  set<int> s;
  forr(i, n) s.insert(a[i]);
  map<int, int> m;
  for (auto x : a) m[x]++;
  for (auto x : m) x.second--;
  // alice will choose the smallest number from the set (just assume that alice can only see the set)
  // bob will try to eat away all the ones which aren't duplicates
  // and then, bob will eat the largest duplicates
  // so, alice will be left with the smallest duplicates

  // no, bob will try to eat away all the duplicates, so that alice, has to move up to the next smallest number
  int ans = 0;
  int aliceMax = 0;
  int turn = 0;
  while (s.size()) {
    int x = *s.begin();
    if (m[x] == 0) {
      s.erase(s.begin());
      if (turn == 0) {
        ans++;
        aliceMax = x;
        turn = 1;
      } else {
        turn = 0;
      }
      continue;
    } else {
      if (turn == 0) {
        if (x > aliceMax) {
          ans++;
          aliceMax = x;
          continue;
        } else {
          int y;
          for (auto z : s) {
            if (z > aliceMax) {
              y = z;
              break;
            }
          }
        }
        turn = 1;
      } else {
        m[x]--;
        turn = 0;
      }
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