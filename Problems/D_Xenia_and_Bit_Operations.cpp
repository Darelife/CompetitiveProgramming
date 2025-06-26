// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;

// #define int long long
// #define debug(x) cout << #x << " = " << x << "\n";
// #define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

// #define f(i, a, b) for (int i = a; i < b; i++)
// #define pba push_back

// typedef vector<int> vint;
// #define vcin(vint, n) f(i, 0, n) cin >> vint[i]
// #define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;

// #define endl '\n'
// const int inf = 1e9 + 5;
// const int MOD = 1e9 + 7;

// vint a(140000); // 0 based
// vint seg(4 * 140000); // 1 based

// void build(int s, int e, int index, int level) { // O(N)
//   if (s == e) {
//     seg[index] = a[s];
//     return;
//   }
//   int mid = s + (e - s) / 2;
//   build(s, mid, 2 * index, level - 1);
//   build(mid + 1, e, 2 * index + 1, level - 1);
//   if (level % 2 == 1) {
//     seg[index] = seg[2 * index] | seg[2 * index + 1];
//   } else {
//     seg[index] = seg[2 * index] ^ seg[2 * index + 1];
//   }
// }

// void update(int s, int e, int index, int updateIndex, int updateValue, int level) { // O(logN)
//   if (s == e) {
//     seg[index] = updateValue;
//     return;
//   }
//   int mid = s + (e - s) / 2;
//   if (updateIndex <= mid) {
//     update(s, mid, 2 * index, updateIndex, updateValue, level - 1);
//   } else {
//     update(mid + 1, e, 2 * index + 1, updateIndex, updateValue, level - 1);
//   }
//   if (level % 2 == 1) {
//     seg[index] = seg[2 * index] | seg[2 * index + 1];
//   } else {
//     seg[index] = seg[2 * index] ^ seg[2 * index + 1];
//   }
// }

// void solve() {
//   int n, q;
//   cin >> n >> q;
//   int N = 1 << n;
//   vcin(a, N);
//   build(0, N - 1, 1, n);
//   for (int i = 0; i < q; i++) {
//     int p, b;
//     cin >> p >> b;
//     update(0, N - 1, 1, p - 1, b, n);
//     cout << seg[1] << endl;
//   }
// }

// int32_t main() {
//   ios::sync_with_stdio(0); cin.tie(0);
//   int t = 1;
//   while (t--) solve();
// }

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

// TLE's template
template<typename Node, typename Update>
struct SegTree {
  vector<Node> tree; //* segment tree array
  vector<int> arr; //* original array (type may change)
  int n; //* size of original array
  int s; //* size of segment tree
  int levels; //* number of levels in the segment tree

  SegTree(int a_len, vector<int>& a) { //* change if type updated
    arr = a;
    n = a_len;
    s = 1;
    while (s < 2 * n) {
      s = s << 1; //* instead of directly putting it as 4n, we are doing this
    }
    tree.resize(s); fill(tree.begin(), tree.end(), Node());
    levels = 0;
    int tmp = n;
    while (tmp > 1) {
      tmp >>= 1;
      levels++;
    }
    build(0, n - 1, 1, levels);
  }
  void build(int start, int end, int index, int level)  //! Never change this
  {
    if (start == end) {
      tree[index] = Node(arr[start], level);
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index, level - 1);
    build(mid + 1, end, 2 * index + 1, level - 1);
    tree[index] = Node(0, level); // set level for internal node
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }
  void update(int start, int end, int index, int query_index, Update& u, int level)
  {
    if (start == end) {
      u.apply(tree[index]);
      return;
    }
    int mid = (start + end) / 2;
    if (mid >= query_index)
      update(start, mid, 2 * index, query_index, u, level - 1);
    else
      update(mid + 1, end, 2 * index + 1, query_index, u, level - 1);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }
  Node query(int start, int end, int index, int left, int right) { // Never change this
    if (start > right || end < left)
      return Node();
    if (start >= left && end <= right)
      return tree[index];
    int mid = (start + end) / 2;
    Node l, r, ans;
    l = query(start, mid, 2 * index, left, right);
    r = query(mid + 1, end, 2 * index + 1, left, right);
    ans = Node(0, tree[index].level); // set correct level
    ans.merge(l, r);
    return ans;
  }
  void make_update(int index, long long val) {  // pass in as many parameters as required
    Update new_update = Update(val); // may change
    update(0, n - 1, 1, index, new_update, levels);
  }
  Node make_query(int left, int right) {
    return query(0, n - 1, 1, left, right);
  }
};

struct Node1 {
  int val, level; // may change
  Node1() { // Identity element
    val = 0;  // may change
    level = 0;
  }
  Node1(int p1, int l) {  // Actual Node
    val = p1; // may change
    level = l;
  }
  void merge(const Node1& l, const Node1& r) { // Merge two child nodes
    if (level % 2 == 1) {
      val = l.val | r.val;
    } else {
      val = l.val ^ r.val;
    }
  }
};

struct Update1 {
  int val; // may change
  Update1(int p1) { // Actual Update
    val = p1; // may change
  }
  void apply(Node1& a) { // apply update to given node
    a.val = val; // may change
  }
};



void solve() {
  int N, q;
  cin >> N >> q;
  int n = 1 << N;
  vint a(n);
  vcin(a, n);

  SegTree<Node1, Update1> sg = SegTree<Node1, Update1>(n, a);
  for (int i = 0; i < q; i++) {
    int p, b;
    cin >> p >> b;
    sg.make_update(p - 1, b);
    cout << sg.tree[1].val << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}