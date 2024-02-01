#include <bits/stdc++.h>
// #include <math.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define la(i, n) for (int i = 0; i < n; i++)  // loop around
#define ela(i, n) for (int i = 0; i < n; i++) // Equal Loop Around
#define pba push_back
#define pfa push_front
#define popb pop_back
#define popf pop_front
#define gla(i, a, n) for (int i = a; i < n; i++) // general loop around
#define empb emplace_back
#define empf emplace_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()
#define sq(x) ((x) * (x))
#define lasqr(i, n) for (int i = 0; i * i < n; i++) // loop around square root
#define mpair make_pair
#define mtuple make_tuple

typedef vector<int> vint;
typedef vector<ll> vill;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

void solve() {
  int n;
  cin >> n;
  int count = 0;
  if (n <= 10) {
    cout << n << endl;
  } else if (n <= 100) {
    count += 9;
    count += n / 10;
    cout << count << endl;
  } else if (n <= 1000) {
    count += 18;
    count += (n / 100);
    cout << count << endl;
  } else if (n <= 10000) {
    count += 27;
    count += (n / 1000);
    cout << count << endl;
  } else if (n <= 100000) {
    count += 36;
    count += (n / 10000);
    cout << count << endl;
  } else if (n <= 1000000) {
    count += 45;
    count += (n / 100000);
    cout << count << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}