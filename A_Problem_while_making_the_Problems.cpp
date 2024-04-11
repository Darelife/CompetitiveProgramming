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

// int b(int n) {
//   if (n != 1) {
//     return 1 + b(n / 2);
//   }
//   if (n == 1)
//     return 1;
// }
void solve() {
  int n;
  cin >> n;
  // n -= 1;
  if (n <= 1)
    cout << 0;
  else if (n <= 2)
    cout << 1;
  else if (n <= 4)
    cout << 2;
  else if (n <= 8)
    cout << 3;
  else if (n <= 16)
    cout << 4;
  else if (n <= 32)
    cout << 5;
  else if (n <= 64)
    cout << 6;
  else if (n <= 128)
    cout << 7;
  else if (n <= 256)
    cout << 8;
  else if (n <= 512)
    cout << 9;
  else if (n <= 1024)
    cout << 10;
  else if (n <= 2048)
    cout << 11;
  else if (n <= 4096)
    cout << 12;
  else if (n <= 4096 * 2)
    cout << 13;
  else if (n <= 4096 * 4)
    cout << 14;
  else if (n <= 4096 * 8)
    cout << 15;
  else if (n <= 4096 * 16)
    cout << 16;
  else if (n <= 4096 * 32)
    cout << 17;
  else if (n <= 4096 * 64)
    cout << 18;
  else if (n <= 4096 * 128)
    cout << 19;
  else if (n <= 4096 * 256)
    cout << 20;
  else if (n <= 4096 * 512)
    cout << 21;
  else if (n <= 4096 * 1024)
    cout << 22;
  else if (n <= 4096 * 2048)
    cout << 23;
  else if (n <= 4096 * 4096)
    cout << 24;
  else if (n <= 4096 * 4096 * 2)
    cout << 25;
  else if (n <= 4096 * 4096 * 4)
    cout << 26;
  else if (n <= 4096 * 4096 * 8)
    cout << 27;
  else if (n <= 4096 * 4096 * 16)
    cout << 28;
  else if (n <= 4096 * 4096 * 32)
    cout << 29;
  else if (n <= 4096 * 4096 * 64)
    cout << 30;
  else if (n <= 4096 * 4096 * 128)
    cout << 31;
  else if (n <= 4096 * 4096 * 256)
    cout << 32;
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}