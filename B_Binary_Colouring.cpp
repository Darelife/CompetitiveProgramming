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

vint res(int num) {
  vint ans;
  while (num > 0) {
    if (num % 2 == 0) {
      ans.pba(0);
      num /= 2;
    } else {
      if (num % 4 == 1) {
        ans.push_back(1);
        num = (num - 1) / 2;
      } else {
        ans.push_back(-1);
        num = (num + 1) / 2;
      }
    }
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vint ans = res(n);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
signed main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
