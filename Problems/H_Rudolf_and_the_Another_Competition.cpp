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

#define piii pair<int,pii>

bool customComparator(const piii& a, const piii& b) {
  if (a.first != b.first) return a.first > b.first; // Points in decreasing order
  if (a.second.first != b.second.first) return a.second.first < b.second.first; // Penalty in increasing order
  return a.second.second < b.second.second; // Index in increasing order
}

void solve() {
  // int n, m, k;
  // cin >> n >> m >> k;
  // vector<vint> a(n, vint(m));
  // // cout << "--------" << endl;
  // forr(i, n) {
  //   vcin(a[i], m);
  // }
  // forr(i, n) {
  //   sort(allEle(a[i]));
  // }
  // // vector<pii> pointsPenalty;
  // vector <pair<int, pair<int, int>>> pp;
  // forr(i, n) {
  //   int points = 0, penalty = 0;
  //   forr(j, m) {
  //     if (a[i][j] < k) {
  //       points++;
  //       penalty += a[i][j];
  //     }
  //   }
  //   pp.pba({ points, {penalty, i} });
  // }
  // // sort(allEle(pp), greater<pair<int, pair<int, int>>>());
  // sort(allEle(pp), customComparator);
  // for (int i = 0; i < n; i++) {
  //   if (pp[i].second.second == 0) {
  //     cout << i + 1 << endl;
  //     return;
  //   }
  // }
  // cout << n << endl;
  int n, m, k;
  cin >> n >> m >> k;
  // cout << n << " " << m << " " << k << endl;
  vector<pii> rank(n);
  forr(i, n) {
    vint p(m);
    vcin(p, m);
    sort(allEle(p));

    int timeL = k;
    int penalty = 0, timeP = 0;
    int points = 0;
    forr(j, m) {
      if (p[j] <= timeL) {
        points++;
        penalty += timeP + p[j];
        timeP += p[j];
        timeL -= p[j];
      }
      else break;
    }
    rank[i] = { points, penalty };
  }
  // debug(rank.size(), n);
  // if (n == 1) { cout << 1 << endl; return; }
  pii me = rank[0];
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (me.first < rank[i].first) {
      ans++;
    }
    else if (me.first == rank[i].first && me.second > rank[i].second) {
      ans++;
    }
  }
  // if (ans == 0) ans++;
  cout << ans + 1 << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}