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

#define endl '\n'
const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // Step 1: Find the last occurrence of each element
  map<int, int> last_occurrence;
  for (int i = 0; i < n; ++i) {
    last_occurrence[a[i]] = i;
  }

  // Step 2: Count the segments
  int segments = 0;
  int max_last_occurrence = -1;
  set<int> current_elements;

  for (int i = 0; i < n; ++i) {
    max_last_occurrence = max(max_last_occurrence, last_occurrence[a[i]]);
    current_elements.insert(a[i]);

    // Check if the current segment can end
    if (i == max_last_occurrence) {
      segments++;
      current_elements.clear(); // Clear the set for the next segment
    }
  }

  cout << segments << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}