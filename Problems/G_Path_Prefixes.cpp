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

struct node {
  int u,a,b;
};

void dfs(node u, vector<vector<node>> &adj, int &aSum, int &bSum, vector<int>&pre, vector<int>&r) {
  for (auto v:adj[u.u]) {
    aSum += v.a;
    bSum += v.b;
    pre.pba(bSum);
    r[v.u]=upper_bound(pre.begin(), pre.end(), aSum) - pre.begin();
    dfs(v, adj, aSum, bSum, pre, r);
    aSum -= v.a;
    bSum -= v.b;
    pre.pop_back();
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<node>> adj(n);
  for (int i = 0; i<n-1; i++) {
    int p, a, b;
    cin >> p >> a >> b;
    p--;
    node t = {i+1, a, b};
    adj[p].push_back(t);
  }
  int aSum = 0, bSum = 0;
  vint preB;
  vint r(n);
  node t = {0, 0, 0};
  dfs(t, adj, aSum, bSum, preB, r);
  for (int i = 1; i<n; i++) {
    cout << r[i] << " ";
  }
  cout << endl;
}
int knapsack(vint w, vint c, int capacity) {
  vint dp(capacity + 1, 0);
  int n = w.size();
  for (int i = 1; i <= n; i++) {
    for (int j = capacity; j >= 0; j--) {
      if (w[i - 1] <= j) {
        dp[j] = max(dp[j], dp[j - w[i - 1]] + c[i - 1]);
      }
    }
  }
  return dp[capacity];
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; cin >> t;
  while (t--) solve();
}