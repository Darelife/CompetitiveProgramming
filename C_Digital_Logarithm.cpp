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


void push(std::vector<int>& vec, int value) {
  auto it = std::lower_bound(vec.begin(), vec.end(), value, std::greater<int>());
  vec.insert(it, value);
}

void pop(std::vector<int>& vec) {
  if (!vec.empty()) {
    vec.erase(vec.begin());
  }
}

void solve() {
  int n;
  cin >> n;

  //* M1
  priority_queue<int, vector<int>, less<int>> pq1, pq2;
  forr(i, n) {
    int a;
    cin >> a;
    pq1.push(a);
  }
  forr(i, n) {
    int a;
    cin >> a;
    pq2.push(a);
  }
  int ans = 0;
  while (!pq1.empty() && !pq2.empty()) {
    if (pq1.top() == pq2.top()) {
      pq1.pop(), pq2.pop();
    } else {
      if (pq1.top() > pq2.top()) {
        pq1.push(log10(pq1.top()) + 1), pq1.pop();
      } else if (pq1.top() < pq2.top()) {
        pq2.push(log10(pq2.top()) + 1), pq2.pop();
      }
      ans++;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}