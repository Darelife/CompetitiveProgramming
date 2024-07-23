#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  // your code goes here
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> m;
    int outOfPlace = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    int endloop = 0;
    for (int i = 0; i < n; i++) {
      if (endloop) break;
      cin >> b[i];
      m[b[i]]--;
      if (a[i] != b[i]) {
        outOfPlace++;
      }
      if (m[b[i]] < 0) {
        cout << "NO" << endl;
        endloop = 1;
      }
    }
    if (endloop) continue;
    if (n == 2) {
      if (a[0] != b[0] && k % 2 == 0) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
      continue;
    }
    if (outOfPlace / 2 >= k) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
