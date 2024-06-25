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
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  vint b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    b[i] = __gcd(a[i], a[i + 1]);
  }

  int index = -1;
  for (int i = 0; i < n - 2; i++) {
    if (b[i] > b[i + 1]) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    cout << "YES" << endl;
    return;
  }

  // if index is the answer
  vint aa(n - 1);
  for (int i = 0; i < n; i++) {
    if (i != index)
      aa[i] = a[i];
  }
  vint aaa(n - 1);
  for (int i = 0; i < n; i++) {
    if (i != index + 1) {
      aaa[i] = a[i];
    }
  }
  vint aaaa(n - 1);
  for (int i = 0; i < n; i++) {
    if (i != index + 2) {
      aaaa[i] = a[i];
    }
  }

  vint bb(n - 2);
  vint bbb(n - 2);
  vint bbbb(n - 2);
  for (int i = 0; i < n - 2; i++) {
    bb[i] = __gcd(aa[i], aa[i + 1]);
    bbb[i] = __gcd(aaa[i], aaa[i + 1]);
    bbbb[i] = __gcd(aaaa[i], aaaa[i + 1]);
  }

  int f = 0;
  int ff = 0;
  int fff = 0;
  for (int i = 0; i < n - 3; i++) {
    if (bb[i] > bb[i + 1]) {
      f = 1;
      // cout << "NO" << endl;
      // return;
    }
    if (bbb[i] > bbb[i + 1]) {
      ff = 1;
    }
    if (bbbb[i] > bbbb[i + 1]) {
      fff = 1;
    }
  }
  if (f && ff && fff) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}