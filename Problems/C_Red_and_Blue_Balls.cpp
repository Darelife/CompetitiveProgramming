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

vector<vector<int>> d(1e6 + 2, vector<int>(1e6 + 2));
int s1 = 0, s2 = 0;

int dp(int i, int j) {
  if (i == 1 && j == 1) {

  }
}

void solve() {
  s1 = 0, s2 = 0;
}

int32_t main() {
  int t = 1;
  while (t--) solve();
}