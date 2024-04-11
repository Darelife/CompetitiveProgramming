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
  int n, w;
  cin >> n >> w;

  // Storing the count of each box size
  vi a(32, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[log2(x)] += 1;
  }

  // Simulating
  int h = 1, space = w;
  la(i, 0, n) {
    int switchLine = -1; // -1 means no box can fit in the remaining space
    rla(j, 31) {
      if ((pow(2, j)) <= space && a[j] != 0) {
        // Found a box that can fit in the remaining space
        switchLine = j;
        break;
      }
    }
    if (switchLine == -1) {
      // No box can fit in the remaining space
      h++;
      space = w;
      // Reset the space, and move to the next line
      rla(j, 31) {
        if (pow(2, j) <= space && a[j] != 0) {
          switchLine = j;
          break;
        }
      }
    }
    space -= (pow(2, switchLine));
    a[switchLine]--;
  }
  cout << h << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}