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
  int w, h;
  cin >> w >> h;
  int n1;
  cin >> n1;
  vi a(n1);
  for (auto &i : a) {
    cin >> i;
  }
  int n2;
  cin >> n2;
  vi b(n2);
  for (auto &i : b) {
    cin >> i;
  }
  int n3;
  cin >> n3;
  vi c(n3);
  for (auto &i : c) {
    cin >> i;
  }

  int n4;
  cin >> n4;
  vi d(n4);
  for (auto &i : d) {
    cin >> i;
  }

  sort(allEle(a));
  sort(allEle(b));
  sort(allEle(c));
  sort(allEle(d));

  int ans1 = (a[n1 - 1] - a[0]) * h;
  int ans2 = (b[n2 - 1] - b[0]) * h;
  int ans3 = (c[n3 - 1] - c[0]) * w;
  int ans4 = (d[n4 - 1] - d[0]) * w;
  cout << max({ans1, ans2, ans3, ans4}) << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}