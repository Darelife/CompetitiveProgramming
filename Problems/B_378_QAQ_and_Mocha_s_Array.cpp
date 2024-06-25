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

void solve() {
  int n;
  cin >> n;
  vint arr(n);
  vcin(arr, n);
  sort(allEle(arr));
  int a1 = arr[0];
  int a2 = arr[1];
  if (a2 % a1 == 0) {
    for (int i = 0; i < n; i++) {
      if (arr[i] % a1 != 0) {
        a2 = arr[i];
        break;
      }
    }
  }

  if (a1 == 1) {
    cout << "Yes" << endl;
    return;
  }

  forr(i, n) {
    if ((arr[i] % a1 != 0) && (arr[i] % a2 != 0)) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}