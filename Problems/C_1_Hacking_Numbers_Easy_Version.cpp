#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define f(i, a, b) for (int i = a; i < b; i++)
#define pba push_back

typedef vector<int> vint;
#define vcin(vint, n) f(i, 0, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;

// #define endl '\n'
const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;


  int temp;
  // cout << "mul 9" << endl;
  // cin >> temp;
  // cout << "digit" << endl;
  // cin >> temp;
  // cout << "digit" << endl;
  // cin >> temp;
  // cout << "add " << n - 9 << endl;
  // cin >> temp;
  // cout << "!" << endl;
  // cin >> temp;
  cout << "mul 999999999" << endl;
  cin >> temp;
  cout << "digit" << endl;
  cin >> temp;
  if (n == 81) {
    cout << "!" << endl;
    cin >> temp;
    return;
  }
  cout << "add " << n - 81 << endl;
  cin >> temp;
  cout << "!" << endl;
  cin >> temp;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}