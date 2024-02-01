// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// void printvec(vector<int> a) {
//   for (int i = 0; i < a.size(); i++) {
//     cout << a[i] << " ";
//   }
//   cout << endl;
// }

// void print(auto a) { cout << a << endl; }

// void solve(int n, string s) {
//   int point1 = 1, point2 = 1, ans = 0;
//   while (s[point1] == 'B') {
//     point1++;
//     point2++;
//   }
//   while (point1 < n) {
//     int countB = 0;
//     while (s[point2] == 'A')
//       point2++;
//     while (s[point2] == 'B')
//       point2++, countB++;
//     if (s[point2 - 1] == 'B')
//       ans += point2 - point1 - 1;
//     if (countB > 0)
//       point1 = point2-1;
//     else
//       break;
//   }
//   cout << ans << endl;
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   int t = 1;
//   cin >> t;
//   while (t--) {
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     solve(n, s);
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

char s[200005];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc, n;
  cin >> tc;
  while (tc--) {
    cin >> n;
    s[n + 1] = 'C';
    for (int i = 1; i <= n; ++i)
      cin >> s[i];
    int pt1 = 1, pt2 = 1, ans = 0;
    while (s[pt1] == 'B')
      ++pt1, ++pt2;
    while (pt1 <= n) {
      int cntA = 0, cntB = 0;
      while (s[pt2] == 'A')
        ++pt2, ++cntA;
      while (s[pt2] == 'B')
        ++pt2, ++cntB;
      if (s[pt2 - 1] == 'B')
        ans += pt2 - pt1 - 1;
      if (cntB)
        pt1 = pt2 - 1;
      else
        break;
    }
    cout << ans << '\n';
  }
}