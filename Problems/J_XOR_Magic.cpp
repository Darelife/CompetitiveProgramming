#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1) cout << 1 << endl;
  else if (n % 2) { for (int i = 0; i < n; i++) cout << 1 << " "; cout << endl; } else { cout << 1 << " "; for (int i = 0; i < n - 2; i++) cout << 2 << " "; cout << 3 << endl; }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}