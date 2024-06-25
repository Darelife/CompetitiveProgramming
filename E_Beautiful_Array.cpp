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

int digitSum(int n) {
  if (n < 10) return n;
  return n % 10 + digitSum(n / 10);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vint a(n);
  vcin(a, n);

  map<int, set<int>> group;
  for (int elem : a) {
    auto& g = group[elem % k];
    if (g.count(elem)) g.erase(elem);
    else g.insert(elem);
  }

  int oddCount = 0, oddKey = -1;
  for (const auto& [key, val] : group) {
    if (val.size() & 1) {
      oddCount++;
      oddKey = key;
    }
  }

  if (oddCount != 1 && oddCount != 0) {
    cout << -1 << endl;
    return;
  }

  int result = 0;
  for (const auto& [key, val] : group) {
    if (key == oddKey) continue;
    auto it = val.begin();
    while (distance(it, val.end()) > 1) {
      auto first = it++;
      auto second = it++;
      result += (*second - *first) / k;
    }
  }

  if (oddCount) {
    vint oddElements(allEle(group[oddKey]));
    int m = oddElements.size();
    if (m == 1) {
      cout << result << endl;
      return;
    }
    vint pre(m, 0), suf(m, 0);
    for (int i = 1; i < m; i += 2) {
      pre[i] = oddElements[i] - oddElements[i - 1];
      if (i > 1) pre[i] += pre[i - 2];
    }
    for (int i = m - 2; i >= 0; i -= 2) {
      suf[i] = oddElements[i + 1] - oddElements[i];
      if (i < m - 2) suf[i] += suf[i + 2];
    }
    int minAdjustment = inf;
    for (int i = 0; i < m; i += 2) {
      int adjustment = (i > 0 ? pre[i - 1] : 0) + (i + 1 < m ? suf[i + 1] : 0);
      minAdjustment = min(minAdjustment, adjustment);
    }
    result += minAdjustment / k;
  }
  cout << result << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}

