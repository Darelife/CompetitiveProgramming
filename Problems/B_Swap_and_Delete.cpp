#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void testcase() {
  string s;
  cin >> s;
  int n = s.size();
  vector<char> t;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    m[s[i] - '0']++;
  }
  for (int i = 0; i < n + 1; i++) {
    if (i == s.size() || m[1 - s[i] + '0'] == 0) {
      cout << (s.size() - i) << endl;
      break;
    }
    m[1 - s[i] + '0'] -= 1;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}