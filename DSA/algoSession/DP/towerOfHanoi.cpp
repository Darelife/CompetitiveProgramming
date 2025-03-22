#include <iostream>
using namespace std;

#define int long long

long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int ans = 0;
void solve(int n, char a, char b, char c) {
  if (n == 1) {
    cout << "Move 1 from " << a << " to " << b << endl;
    return;
  }
  solve(n - 1, a, c, b);
  cout << "Move " << n << " from " << a << " to " << b << endl;
  solve(n - 1, c, b, a);
  ans += 2;
}

signed main() {
  int n;
  cin >> n;
  solve(n, 'A', 'C', 'B');
  cout << ans + 1 << endl;
  return 0;
}