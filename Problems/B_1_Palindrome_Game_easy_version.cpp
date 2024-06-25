#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define la(i, a, n) for (int i = a; i < n; i++)      // loop around
#define rla(i, n) for (int i = n; i >= 0; i--)       // reverse loop around
#define ela(i, a, n) for (int i = a; i <= n; i++)    // Equal Loop Around
#define lasqr(i, n) for (int i = 1; i * i <= n; i++) // loop around square root
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vi;

const int inf = 1e9 + 5;

int isPalindrome(string s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1])
      return 0;
  }
  return 1;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = "BOB";
  // int alice = 1;
  int zeroes = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      // alice = 0;
      // break;
      zeroes++;
    }
  }
  cout << ((!zeroes || (n % 2 == 1 && s[n / 2] == '0' && zeroes != 1)) ? "ALICE"
                                                                       : "BOB")
       << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}