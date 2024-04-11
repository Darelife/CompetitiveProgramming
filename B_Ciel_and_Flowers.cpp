#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define la(i, a, n) for (int i = a; i < n; i++)      // loop around
#define ela(i, a, n) for (int i = a; i <= n; i++)    // Equal Loop Around
#define lasqr(i, n) for (int i = 1; i * i <= n; i++) // loop around square root
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vi;

const int inf = 1e9 + 5;

int min3(int a, int b, int c) {
  a = (a < b) ? a : b;
  a = (a < c) ? a : c;
  return a;
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int t = 0;
  int ans = 0;
  if (a % 3 == 2)
    t++;
  if (b % 3 == 2)
    t++;
  if (c % 3 == 2)
    t++;
  if (t == 2 && min3(a, b, c) > 0)
    ans++;

  ans += a / 3 + b / 3 + c / 3 + (min3(a % 3, b % 3, c % 3));
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}