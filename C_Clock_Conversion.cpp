#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define la(i, a, n) for (int i = a; i < n; i++)      // loop around
#define rla(i, n) for (int i = n; i >= 0; i--)       // reverse loop around
#define ela(i, a, n) for (int i = a; i <= n; i++)    // Equal Loop Around
#define lasqr(i, n) for (int i = 1; i * i <= n; i++) // loop around square root
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vi;

const int inf = 1e9 + 5;

void solve() {
  string s;
  cin >> s;
  int h = stoi(s.substr(0, 2));
  int m = stoi(s.substr(3, 4));
  if (h >= 12 && h != 24) {
    if (h != 12)
      h -= 12;
    cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m
         << " PM" << endl;
  } else {
    cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m
         << " AM" << endl;
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