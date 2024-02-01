#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define la(i, n) for (int i = 0; i < n; i++)       // loop around
#define ela(i, n) for (int i = 0; i < n; i++)      // Equal Loop Around
#define lasq(i, n) for (int i = 0; i * i < n; i++) // loop around square root
#define gla(i, a, n) for (int i = a; i < n; i++)   // general loop around
#define pba push_back
#define pfa push_front
#define popb pop_back
#define popf pop_front
#define empb emplace_back
#define empf emplace_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()
#define sq(x) ((x) * (x))
#define mpair make_pair
#define mtuple make_tuple

typedef vector<int> vint;
typedef vector<ll> vill;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

void solve() {
  ll a, b;
  cin >> a >> b;
  if (b == 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  ll t = a * (b + 1);
  cout << a << " " << t - a << " " << t << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}