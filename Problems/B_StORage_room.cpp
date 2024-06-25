#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));
  for (auto &x : a) {
    for (auto &y : x) {
      cin >> y;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && a[i][j] == 0) {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";

  for (int i = 0; i < n; i++) {
    cout << a[i][0] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}