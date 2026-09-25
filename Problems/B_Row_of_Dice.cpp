#include <bits/stdc++.h>
using namespace std;
#define int long long

const long long MOD = 998244353;
long long modpow(long long a, long long b) {
  long long res = 1; a %= MOD;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long modinv(long long q) { return modpow(q, MOD - 2); }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  vector<int> s(n);
  s[n - 1] = 0;
  for (int i = n - 2; i >= 0;i--) {
    s[i] = max(s[i + 1], a[i]);
  }

  double ans = 0;
  int carry = 1;
  int num = 1;
  for (int i = 0; i < n; i++) {
    // int t = (s[i]) / 2;
    int t = s[i] * (s[i] + 1) / 2;
    t /= s[i];
    if (t > a[i]) continue;
    int sum = a[i] * (a[i] + 1) / 2;
    sum -= (t) * (t + 1) / 2;
    int x = num * sum / (a[i] * carry);
    ans += x;
    carry *= a[i];
    num *= t;
  }
  cout << ans << endl;
}

int32_t main() {
  int t = 1;
  while (t--) solve();
}