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

void solve() {
  string s;
  cin >> s;
  vector<string> v;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') v.push_back("O-|-OOOO");
    else if (s[i] == '1') v.push_back("O-|O-OOO");
    else if (s[i] == '2') v.push_back("O-|OO-OO");
    else if (s[i] == '3') v.push_back("O-|OOO-O");
    else if (s[i] == '4') v.push_back("O-|OOOO-");
    else if (s[i] == '5') v.push_back("-O|-OOOO");
    else if (s[i] == '6') v.push_back("-O|O-OOO");
    else if (s[i] == '7') v.push_back("-O|OO-OO");
    else if (s[i] == '8') v.push_back("-O|OOO-O");
    else if (s[i] == '9') v.push_back("-O|OOOO-");
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}