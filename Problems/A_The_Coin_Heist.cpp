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

vector<int> fact(1e6 + 2), ifact(1e6 + 2);

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 499122177 << endl;
    return;
  }
  int p = 0;
  for (int i = 0; i < n; i++) {
    int x = ((n - i) * fact[n - 1]) % MOD;
    x = (x * ifact[i]) % MOD;
    x = (x * ifact[n - 1 - i]) % MOD;
    p += x;
    cout << x << endl;
  }
  // int p =
  if (n > 2) p = (p * modpow(2ll, (n - 2) * (n - 1) / 2)) % MOD;
  int q = n * (n - 1) / 2 + 1;
  // if (n >= 3) q++;
  int qq = modpow(2ll, q);
  int qqq = modinv(qq);
  int ans = (p * qqq) % MOD;
  cout << p << " " << q << endl;
  cout << ans << endl;
}

int32_t main() {
  int t = 1;
  cin >> t;
  fact[0] = 1;
  for (int i = 1; i <= 1e6; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  ifact[1e6] = modinv(fact[1e6]);
  for (int i = 1e6 - 1; i > 0; i--) {
    ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
  }
  ifact[0] = 1;
  while (t--) solve();
}