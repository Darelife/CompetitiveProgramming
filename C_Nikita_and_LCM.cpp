#include <bits/stdc++.h>
using namespace std;

#define intt int
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

int lcm(int a, int b) {
  return (a * b) / __gcd(a, b);
}

void solve() {
  // cout << "HELLLLLLO" << endl;
  int n;
  cin >> n;
  vint a(n);
  // cout << "HELLLLLLO" << endl; 
  vcin(a, n);
  // cout << 2 << endl;

  sort(allEle(a));
  forr(i, n) {
    if (a[n - 1] % a[i] != 0) {
      cout << n << endl;
      return;
    }
  }
  vint factors; //factors of a[n - 1]
  sqforr(i, a[n - 1]) {
    if (a[n - 1] % i == 0) {
      factors.pba(i);
      factors.pba(a[n - 1] / i);
    }
  }
  int ans = 0;
  // go to every factor
  // make sure that it isn't in the array
  // find the elements which can divide the factor
  // check if the lcm of those numbers is the factor
  // if yes, choose the maximum of the number of elements and the ans
  forr(i, factors.size()) {
    if (find(allEle(a), factors[i]) != a.end()) continue;
    int tempLcm = 1;
    int tempAns = 0;
    for (int j = 0; j < n; j++) {
      if (!(factors[i] % a[j])) {
        tempLcm = lcm(tempLcm, a[j]);
        tempAns++;
      }
    }
    if (tempLcm == factors[i]) {
      ans = max(ans, tempAns);
    }
  }
  cout << ans << endl;
  return;
}

signed main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    // cout << i << endl;
    solve();
  }
}