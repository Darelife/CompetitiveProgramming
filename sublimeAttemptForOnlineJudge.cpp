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

const int inf = 1e9 + 5;

void solve() {}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef ONLINEJUDGE
  clock_t tStart = clock();
  freopen("input.txt", "r", stdin); //can need to change file . this one for taking input
  freopen("output.txt", "w", stdout); // this one for output
#endif
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();

#ifdef ONLINEJUDGE
  fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
#endif

  return 0;
}