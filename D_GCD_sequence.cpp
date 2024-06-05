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

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}


void solve() {
  int n;
  cin >> n;
  vint a(n);
  vcin(a, n);
  vint b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    b[i] = gcd(a[i], a[i + 1]);
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

  // if index is the answer.....(also, cuz of a small number -> 12 3 48 -> 3 3 -> all of them get affected....that's why index, index+1, index+2....(index+1 is the index of the cause of the problem here))
  vint aa, aaa, aaaa;
  for (int i = 0; i < n; i++) {
    if (i != index) {
      aa.pba(a[i]);
    }
    if (i != index + 1) {
      aaa.pba(a[i]);
    }
    if (i != index + 2) {
      aaaa.pba(a[i]);
    }
  }

  vint bb(n - 2), bbb(n - 2), bbbb(n - 2);
  for (int i = 0; i < n - 2; i++) {
    bb[i] = gcd(aa[i], aa[i + 1]);
    bbb[i] = gcd(aaa[i], aaa[i + 1]);
    bbbb[i] = gcd(aaaa[i], aaaa[i + 1]);
  }

  int f = 1;
  int ff = 1;
  int fff = 1;
  for (int i = 0; i < n - 3; i++) {
    if (bb[i] > bb[i + 1]) {
      f = 0;
      break;
      // cout << "NO" << endl;
      // return;
    }
  }
  for (int i = 0; i < n - 3; i++) {
    if (bbb[i] > bbb[i + 1]) {
      ff = 0;
      break;
    }
  }
  for (int i = 0; i < n - 3; i++) {
    if (bbbb[i] > bbbb[i + 1]) {
      fff = 0;
      break;
    }
  }
  if (!(f || ff || fff)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}