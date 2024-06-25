#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> m(n);
  for (ll i = 0; i < n; ++i) {
    cin >> m[i].first;
    m[i].first %= k;
    if (m[i].first == 0) {
      m[i].first = k;
    }
    m[i].second = -1 * i;
  }

  sort(m.begin(), m.end(), greater<pair<ll, ll>>());
  for (ll i = 0; i < n; ++i) {
    cout << -1 * m[i].second + 1 << " ";
  }

  cout << "\n";
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}