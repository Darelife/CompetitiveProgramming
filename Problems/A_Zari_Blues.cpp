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
  //  Assume Co Prime
  // 3 (+) and 5(-)
  // a = 3, b = 5 works
  // a = 6, b = 5 works

  // int t, n, a, b;
  // cin >> t;
  // int P = 0, M = 0;
  // for (int i = 0; i < t; i++) {
  //   char c;
  //   cin >> c;
  //   if (c == '+')
  //     P++;
  //   else
  //     M++;
  // }
  // if (M > P) {
  //   swap(M, P);
  // }
  // cin >> n;
  // la(i, 0, n) {
  //   if ((P == 0 && M == 0) || P == M) {
  //     cout << "YES" << endl;
  //     continue;
  //   }

  //   string ans = "YES";
  //   cin >> a >> b;
  //   // If coprime then it will work
  //   if (max(a, b) % min(a, b) != 0) {
  //     if (min(a, b) <= min(P, M) && max(a, b) <= max(P, M) &&
  //         (a % P == 0 && b % M == 0 || a % M == 0 && b % P == 0))
  //         {
  //       ans = "YES";
  //     } else {
  //       ans = "NO";
  //     }
  //   } else if (a == b) {
  //     if (P == M)
  //       ans = "YES";
  //     else
  //       ans = "NO";
  //   } else {
  //     // When a and b are not coprime
  //     if (min(a, b) > min(P, M) && max(a, b) > max(P, M)) {
  //       if (P % M == 0 && (P / M == max(a, b) / min(a, b))) {
  //         ans = "YES";
  //       } else {
  //         ans = "NO";
  //       }
  //     } else {
  //       if (a > b) {
  //         swap(a, b);
  //       }
  //       if (b / a == (P - M)) {
  //         ans = "YES";
  //       } else {
  //         ans = "NO";
  //       }
  //     }
  //   }
  //   cout << ans << endl;
  // }

  // Rewriting in a clean manner
  int t, n, a, b;
  cin >> t;
  int P = 0, M = 0;
  for (int i = 0; i < t; i++) {
    char c;
    cin >> c;
    if (c == '+')
      P++;
    else
      M++;
  }
  if (M > P) {
    swap(M, P);
  }
  // b > a and P > M

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }

    if (P == M) {
      cout << "YES" << endl;
      // If both are equal then it will work
      continue;
    } else if (a == b) {
      if (P == M)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
      // } else if (b % a == P % M && b / a == P / M && max(a, M) % min(a, M) ==
      // 0) {
      //   cout << "YES" << endl;
      //   continue;
      // } else if (P * a <= b * M && (P - M) % (b / a + b % a - 1) == 0) {
      //   cout << "YES" << endl;
      //   continue;
    } else {
      int x = (P - M) * b / (b - a);
      if (-M <= x && x <= P && x * (b - a) == (P - M) * b) {
        cout << "YES" << endl;
        continue;
      }
    }
    cout << "NO" << endl;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}