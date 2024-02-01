#include <bits/stdc++.h>
#include <bitset>
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
#define rgla(i, a, n)                                                          \
  for (int i = a; i >= n; i--) // reverse general loop
                               // around
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

static void solve() {
  ll a, b, r;
  cin >> a >> b >> r;
  string a1 = "", b1 = "";
  for (ll i = 14; i >= 0; i--) {
    // Go to every bit in a and b, and check if they are the same or not

    // Right shifting
    ll k1 = a >> i;
    ll k2 = b >> i;
    if (k1 == k2) {
      if (k1 == 1) {
        a1 += "0";
        b1 += "0";
      } else {
        a1 += "1";
        b1 += "1";
      }
    } else {
      if (k1 == 1) {
        a1 += "1";
        b1 += "0";
      } else {
        a1 += "0";
        b1 += "1";
      }
    }
  }
  ll a2 = stol(a1, 0, 2);
  ll b2 = stol(b1, 0, 2);
  cout << min(abs(a ^ a2 - b ^ a2), abs(a ^ b2 - b ^ b2)) << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}