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
  int n;
  cin >> n;
  vi A(n * 2);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vi b(m);
    for (int j = 0; j < m; j++) {
      cin >> b[j];
    }
    sort(allEle(b));
    A[i] = b[0];
    A[n + i] = b[1];
  }
  // [A[0],B[0],C[0],A[1],B[1],C[1]]
  int sum = 0;
  for (int i = n; i < 2 * n; i++) {
    sum += A[i];
  }
  int index = 0;
  int min = 1000000000;
  for (int i = 0; i < n; i++) {
    if (A[i] < min) {
      min = A[i];
      index = i;
    }
  }
  sum = sum - A[index + n] + A[index];
  cout << sum << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}