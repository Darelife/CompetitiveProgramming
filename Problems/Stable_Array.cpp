#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vint vector<int>
#define vcin(v, n) for (int i = 0; i < n; ++i) cin >> v[i];

void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);

  queue<int> q;

  for (int i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) {
      q.push(i);
    }
  }

  int ans = 0;

  while (!q.empty()) {
    int size = q.size();
    bool changed = false;

    for (int i = 0; i < size; i++) {
      int idx = q.front();
      q.pop();

      if (a[idx] < a[idx + 1]) {
        a[idx] = a[idx + 1];
        changed = true;

        if (idx - 1 >= 0 && a[idx - 1] < a[idx]) {
          q.push(idx - 1);
        }
      }
    }

    if (changed) {
      ans++;
    }
  }

  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
