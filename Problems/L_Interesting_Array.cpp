#include <bits/stdc++.h>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag,
  tree_order_statistics_node_update>
  ordered_set;

#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
  cerr << endl;
#else
#define debug(x) ;
#endif

class GenericSegmentTree {
private:
  int n;
  std::vector<int> tree;
  const int DEFAULT_VALUE = 0; // 0 for Sum, INT_MAX for Min, INT_MIN for Max

  // This defines how two nodes combine. 
  // Change this to std::min, std::max, or (a ^ b) depending on the question!
  int merge(int left_child, int right_child) {
    return left_child + right_child;
  }

  void build(const std::vector<int>& arr, int node, int start, int end) {
    if (start == end) {
      tree[node] = arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    build(arr, 2 * node, start, mid);
    build(arr, 2 * node + 1, mid + 1, end);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }

  void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
      tree[node] += val; // For frequency tree, you might use tree[node] += val;
      return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }

  int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return DEFAULT_VALUE;
    if (l <= start && end <= r) return tree[node];
    int mid = start + (end - start) / 2;
    return merge(query(2 * node, start, mid, l, r),
      query(2 * node + 1, mid + 1, end, l, r));
  }

public:
  // Constructor 1: Initialize empty tree of size N (Great for Frequency Trees)
  GenericSegmentTree(int size) {
    n = size;
    tree.resize(4 * n, DEFAULT_VALUE);
  }

  // Constructor 2: Build tree from an existing array (Great for Normal Range Queries)
  GenericSegmentTree(const std::vector<int>& arr) {
    n = arr.size();
    tree.resize(4 * n, DEFAULT_VALUE);
    if (n > 0) build(arr, 1, 0, n - 1);
  }

  void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
  int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

/* clang-format off */
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
/* clang-format on */

long long power(long long A, long long B) {
  if (B == 0)
    return 1;
  long long res = power(A, B / 2);
  if (B % 2)
    return res * res * A;
  else
    return res * res;
}

bool isPerfectSquare(long long x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }

  return false;
}

int binarySearch(int arr[], int low, int high, int x) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  // If we reach here, then element was not present
  return low;
}

void solve() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> q(m, vector<int>(3, 0));

  map<pair<int, int>, int> mp;

  for (int i = 0; i < m; i++) {

    cin >> q[i][0];
    cin >> q[i][1];
    cin >> q[i][2];

    if (mp.find({ q[i][0], q[i][1] }) != mp.end()) {
      if (mp[{q[i][0], q[i][1]}] != q[i][2]) {
        cout << "NO" << "\n";
        return;
      }
    } else {
      mp[{q[i][0], q[i][1]}] = q[i][2];
    }

  }

  vector<int> ans(n, 0);
  vector<vector<int>> change(n + 5, vector<int>(32, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 32; j++) {
      if (q[i][2] & (1LL << j)) {
        change[q[i][0] - 1][j]++;
        change[q[i][1]][j]--;
      }
    }
  }

  // how do we check if a segment is within another segment or not?
  // we can store (end, start) in a stack, after sorting by (start,end)
  // and if we find end_stack < start -> pop
  // end_stack > start

  vector<int> run(32, 0);

  cout << "YES" << "\n";

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < 32; j++) {

      run[j] += change[i][j];

      if (run[j] > 0) ans[i] += (1 << j);

    }

    cout << ans[i] << " ";

  }

  cout << "\n";

}

signed main() {

  int t;
  t = 1;

  while (t--) {
    solve();
  }

  return 0LL;
}