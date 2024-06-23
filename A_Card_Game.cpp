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


const int inf = 1e9 + 5;

void solve() {
  char t;
  cin >> t;
  char a1, a2, a3, a4;
  vector<char> o = { '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
  cin >> a1 >> a2 >> a3 >> a4;
  if (a2 == t || a4 == t) {
    if (a2 == t && a4 == t) {
      auto it = find(o.begin(), o.end(), a3);
      int b3 = distance(o.begin(), it);
      auto ik = find(o.begin(), o.end(), a1);
      int b1 = distance(o.begin(), ik);
      if (b1 > b3) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (a2 == t) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (a2 == a4) {
    auto it = find(o.begin(), o.end(), a3);
    int b3 = distance(o.begin(), it);
    auto ik = find(o.begin(), o.end(), a1);
    int b1 = distance(o.begin(), ik);
    if (b1 > b3) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}