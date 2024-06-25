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

const int inf = 1e9 + 5;

void solve() {
  int n;
  cin >> n;
  map<int, int> hash;
  forr(i, n) {
    int x;
    cin >> x;
    hash[x]++;
  }
  int turns = 0;
  int last = 0;
  for (auto &i : hash) {
    if (i.first - last > 1) {
      cout << ((turns % 2 == 0) ? "Alice" : "Bob") << endl;
      return;
    }
    turns++;
    last = i.first;
  }
  // cout << 1;
  cout << ((turns % 2 == 0) ? "Bob" : "Alice") << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}