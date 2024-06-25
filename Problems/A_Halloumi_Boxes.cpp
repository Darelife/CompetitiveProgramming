#include <bits/stdc++.h>
using namespace std;

#define ll long long

void printvec(vector<int> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void print(auto a) { cout << a << endl; }

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  vector<int> b = a;
  sort(b.begin(), b.end());
  int ans = 0;

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      count++;
    }
  }

  if (count == 0) {
    cout << "YES" << endl;
    return;
  }

  if (k>=2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}