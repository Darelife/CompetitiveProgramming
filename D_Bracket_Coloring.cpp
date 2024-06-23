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
  int n;
  cin >> n;
  string s;
  cin >> s;







  int cntA = 0, cntB = 0;
  forr(i, n) {
    if (s[i] == '(') {
      cntA++;
    } else if (s[i] == ')') {
      cntB++;
    }
  }
  if (cntA != cntB) {
    cout << -1 << endl;
    return;
  }








  vint a(n);
  int groupMax = 0, groupMin = 0;
  int group = 0;
  forr(i, n) {
    if (s[i] == '(') {
      group++;
    } else if (s[i] == ')') {
      group--;
    }
    a[i] = group;
    groupMax = max(groupMax, group);
    groupMin = min(groupMin, group);
  }

  if (groupMax == 0 || groupMin == 0) {
    cout << 1 << endl;
    forr(i, n) {
      cout << 1 << " ";
    }
    cout << endl;
    return;
  }








  //* REVERSED RBS = 2, REGULAR RBS = 1
  cout << 2 << endl;
  vint ans(n);
  forr(i, n) {
    // Eg: a = 1, 2, 3, 4, 3, 2, 1, 0, -1, -2, -1, 0
    // now, if it's positive, then it's a regular RBS -> 1
    // if it's negative, then it's a reversed RBS -> 2
    // just 1 catch -> if it's 0, if the last element is positive -> 1, else -> 2
    if (a[i] > 0) {
      ans[i] = 1;
    } else if (a[i] == 0) {
      if (a[i - 1] > 0) {
        ans[i] = 1;
      } else {
        ans[i] = 2;
      }
    } else {
      ans[i] = 2;
    }
  }
  vpin(ans);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}