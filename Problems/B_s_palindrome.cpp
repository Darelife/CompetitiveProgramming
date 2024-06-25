#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;


const int inf = 1e9 + 5;
bool isPalindrome(string s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1])
      return false;
  }
  return true;
}
void solve() {
  string s;
  cin >> s;
  vector<char> sym = { 'A', 'H', 'I', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y' };
  map<char, char> pairs = { {'p', 'q'}, {'q', 'p'}, {'d', 'b'}, {'b', 'd'} };
  vector<char> allowed = { 'A', 'H', 'I', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'p', 'q', 'b', 'd' };

  int lim = (s.size() % 2) ? s.size() / 2 + 1 : s.size() / 2;

  for (int i = 0; i < lim; i++) {
    // not in allowed
    if (find(allEle(allowed), s[i]) == allowed.end()) {
      cout << "NIE" << endl;
      return;
    }
    // if it's in sym, then it should also be at n-i-1
    else if (find(allEle(sym), s[i]) != sym.end()) {
      if (s[i] != s[s.size() - i - 1]) {
        cout << "NIE" << endl;
        return;
      }
    }
    // if it's in pairs, then the pair should be at n-i-1
    else if (pairs.find(s[i]) != pairs.end()) {
      if (s[s.size() - i - 1] != pairs[s[i]]) {
        cout << "NIE" << endl;
        return;
      }
    }
  }

  cout << "TAK" << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}