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

int check(vector<pair<int, int>>& a, vector<tuple<int, int, int>>& v, int mid, vint& res, int s) {
  int m = a.size(), n = v.size(), cost = 0, remainingEle = 0, studGrind = -1;
  vint cnt(n, 0);
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

  for (int i = 0; i < m; i++) {

    int l = 0, r = n - 1, idx = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (get<0>(v[mid]) >= a[i].first) {
        idx = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    for (int j = remainingEle; j <= idx; j++)
      pq.push({ get<1>(v[j]), get<0>(v[j]), get<2>(v[j]) });
    remainingEle = idx + 1;

    if (pq.empty() && studGrind == -1) return -1;

    if (studGrind != -1) {
      res[a[i].second] = studGrind;
      cnt[studGrind]++;
      if (cnt[studGrind] == mid) studGrind = -1;
    } else {
      tuple<int, int, int> ele = pq.top();
      pq.pop();
      cost += get<0>(ele);
      res[a[i].second] = get<2>(ele);
      cnt[get<2>(ele)]++;
      studGrind = get<2>(ele);
      if (cnt[get<2>(ele)] == mid) studGrind = -1;
    }
  }

  if (cost > s) return -1;
  else return cost;
}

void solve() {
  int n, m, s;
  cin >> n >> m >> s;

  vint res(m, -1);
  vector<pair<int, int>> a(m);
  f(i, 0, m) cin >> a[i].first;
  f(i, 0, m) a[i].second = i;


  vector<tuple<int, int, int>> v(n);
  f(i, 0, n) cin >> get<0>(v[i]);
  f(i, 0, n) cin >> get<1>(v[i]);
  f(i, 0, n) get<2>(v[i]) = i;

  sort(a.rbegin(), a.rend());
  sort(v.rbegin(), v.rend());

  vint ans(m, -1);
  int cost = -1;

  int l = 1, r = m;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    res.resize(m, -1);
    int t = check(a, v, mid, res, s);
    if (t == -1) {
      l = mid + 1;
    } else {
      r = mid - 1;
      cost = t;
      ans = res;
    }
  }

  if (cost != -1) {
    for (int i = 0; i < m; i++) ans[i]++;
    cout << "YES\n";
    vpin(ans);
  } else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}