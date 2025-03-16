// heavily inspired from sankabapur's code btw (he explained it to me)

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
  int m = a.size(), n = v.size(), cost = 0, nextInPq = 0, curStud = -1;
  vint cnt(n, 0);
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  f(i, 0, m) {
    int l = 0, r = n - 1, index = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (get<0>(v[mid]) >= a[i].first) {
        index = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    for (int j = nextInPq; j <= index && j < n; j++) {
      pq.push({ get<1>(v[j]), get<0>(v[j]), get<2>(v[j]) });
    }
    nextInPq = index + 1;

    if (pq.empty() && curStud == -1) {
      res.resize(m, -1);
      return -1;
    }
    if (curStud != -1) {
      cnt[curStud]++;
      res[a[i].second] = curStud;
      if (cnt[curStud] == mid) curStud = -1;
    } else {
      tuple<int, int, int> t = pq.top();
      pq.pop();
      cost += get<0>(t);
      int index = get<2>(t);
      cnt[index]++;
      res[a[i].second] = index;
      curStud = index;
      if (cnt[index] == mid) curStud = -1;
    }
  }
  if (cost > s) return -1;
  return cost;
}

void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  vint res(m, -1);
  vector<pair<int, int>> a(m);
  f(i, 0, m) {
    cin >> a[i].first;
    a[i].second = i;
  }
  vint b(n);
  vcin(b, n);
  vint c(n);
  vcin(c, n);
  vector<tuple<int, int, int>> v(n);
  f(i, 0, n) {
    v[i] = { b[i], c[i], i };
  }
  sort(a.rbegin(), a.rend());
  sort(v.rbegin(), v.rend());

  int l = 1, r = 1e5;
  vint ans(m, -1);
  int cost = -1;

  while (l <= r) {
    int mid = l + (r - l) / 2;
    res.resize(m, -1);
    int c = check(a, v, mid, res, s);
    if (c == -1) {
      l = mid + 1;
    } else {
      r = mid - 1;
      cost = c;
      ans = res;
    }
  }
  if (cost == -1) {
    cout << "NO\n";
  } else {
    for (int i = 0; i < m; i++) ans[i]++;
    cout << "YES\n";
    vpin(ans);
  }
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}