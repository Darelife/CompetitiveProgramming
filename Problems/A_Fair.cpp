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
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vint a(n);
  vcin(a, n);
  for (int i = 0; i < n; i++) a[i]--;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    adj[a].pba(b);
    adj[b].pba(a);
  }
  vector<vector<int>> dist(n, vector<int>(k, INT_MAX));

  for (int i = 0; i < k; i++) {
    queue<int> q;
    vector<int> vis(n, 0);
    for (int j = 0; j < n; j++) {
      if (a[j] == i) { q.push(j); vis[j] = 1; dist[j][i] = 0; }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        dist[v][i] = dist[u][i] + 1;
        q.push(v);
      }
    }
  }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < k; j++) {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < n; i++) {
    // // sort(dist[i].begin(), dist[i].end());
    // nth_element(dist[i].begin(), dist[i].begin() + s, dist[i].end());
    // // apparently this is better
    // for (int j = 0; j < s; j++) {
    //   int x = j;
    //   for (int l = j + 1; l < k; l++) {
    //     if (dist[i][l] < dist[i][x]) {
    //       x = l;
    //     }
    //   }
    //   swap(dist[i][j], dist[i][x]); //im trying to manually implement the nth element thing 
    //   // to understand why it's better...it's literally the quick sort thing (partition part)
    // ight, ig i'll need to select the element randomly
    // Manually implement nth_element with random pivot (im using gpt now)
    // int nth = s;
    // auto& vec = dist[i];
    // int l = 0, r = k - 1;
    // while (l < r) {
    //   int pivot_idx = l + rand() % (r - l + 1);
    //   int pivot = vec[pivot_idx];
    //   swap(vec[pivot_idx], vec[r]);
    //   int store = l;
    //   for (int j = l; j < r; j++) {
    //     if (vec[j] < pivot) {
    //       swap(vec[j], vec[store]);
    //       store++;
    //     }
    //   }
    //   swap(vec[store], vec[r]);
    //   if (store == nth) break;
    //   if (store < nth) l = store + 1;
    //   else r = store - 1;
    // }

    // i give up....got to use the nth element thing only :((
    nth_element(dist[i].begin(), dist[i].begin() + s, dist[i].end());
  }

  for (int i = 0; i < n; i++) {
    int ans = 0;
    for (int j = 0; j < s; j++) {
      ans += dist[i][j];
    }
    cout << ans << " ";
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}