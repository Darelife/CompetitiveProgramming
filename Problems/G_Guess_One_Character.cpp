#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  cout << "1 1" << endl;
  cout << "1 10" << endl << "1 11" << endl;
  int a, b, c;
  cin >> a >> b >> c;
  cout << "0 ";
  cout << n;
  cout << " ";
  cout << (!(a == b + c)) << endl;
  int x;
  cin >> x;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}