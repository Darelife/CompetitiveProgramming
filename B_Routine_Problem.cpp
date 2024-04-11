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

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve() {
  // int a, b, c, d;
  // cin >> a >> b >> c >> d;
  // int nu, de;
  // int t = (b * c > a * d) ? 1 : -1;
  // nu = t * (b * c - a * d);
  // de = b * c;
  // int h = gcd(nu, de);
  // cout << nu / h << "/" << de / h << endl;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int nu, de;
  if (a * d > b * c) {
    nu = b * c;
    de = a * d;
  } else {
    nu = a * d;
    de = b * c;
  }
  nu = de - nu;
  int hcf = gcd(nu, de);
  nu = nu / hcf;
  de = de / hcf;
  cout << nu << "/" << de << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}