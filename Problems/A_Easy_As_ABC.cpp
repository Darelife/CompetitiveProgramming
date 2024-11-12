// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ld = long double;

// using pii = pair<int, int>;
// using tii = tuple<int, int, int>;

// const int nmax = 1e6 + 5;
// const int inf = 1e9 + 5;

// // position is a function which takes in a char and returns the position of that char in the vector
// int position(char a, vector<char> v) {
//   for (int i = 0; i < v.size(); i++) {
//     if (v[i] == a) {
//       return i;
//     }
//   }
//   return -1;
// }

// void testcase() {
//   // a 3x3 grid using 2d vectors
//   // save the coordinates as well as the character in the grid

// }

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int t = 1;
//   cin >> t;
//   for (int i = 0; i < t; i++)
//     testcase();
// }

#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;

void __print(int x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const int inf = 1e9 + 5;

int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

const int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

bool isValid(int x, int y) {
  return x >= 0 && x < 3 && y >= 0 && y < 3;
}

void solve() {
  // vector<vector<int>> v(3, vector<int>(3));
  // forr(i, 3) {
  //   forr(j, 3) {
  //     char x;
  //     cin >> x;
  //     v[i][j] = x - 'A';
  //   }
  // }
  // // vector<pii> aPos, bPos, cPos;
  // // forr(i, 3) {
  // //   forr(j, 3) {
  // //     if (v[i][j] == 0) {
  // //       aPos.pba({ i, j });
  // //     } else if (v[i][j] == 1) {
  // //       bPos.pba({ i, j });
  // //     } else {
  // //       cPos.pba({ i, j });
  // //     }
  // //   }
  // // }
  // vector<pair<int, vector<int>>> solutions;
  // // brute force all possible solutions
  // // 1. (0,0) (0,1) (0,2)
  // // 2. (0,0) (0,1) (1,2)
  // // 3. (0,0) (0,1) (1,1)
  // // 4. (0,0) (0,1) (1,0)
  // // 5. (0,0) (1,1) (0,2)

  // // new format
  // // 1. (0,0) (0,1) [(0,2),(1,2),(1,1),(1,0)]
  // // 2. (0,0) (1,1) [(0,1),(0,2),(1,2),(1,0),(2,0),(2,1),(2,2)]
  // // 3. (0,0) (1,0) [(0,1),(0,2),(1,2),(1,1),(2,0),(2,1),(2,2)]
  // // and so on for all possible combinations

  // // implementation
  vector<string> grid(3);
  forr(i, 3) cin >> grid[i];

  set<string> words;

  forr(i, 3) {
    forr(j, 3) {
      forr(d1, 8) {
        int x1 = i + dx[d1], y1 = j + dy[d1];
        if (x1 == i && y1 == j) continue;
        if (!isValid(x1, y1)) continue;
        forr(d2, 8) {
          int x2 = x1 + dx[d2], y2 = y1 + dy[d2];
          if (x2 == i && y2 == j) continue;
          if (x1 == x2 && y1 == y2) continue;
          if (!isValid(x2, y2)) continue;
          string word = "";
          word += grid[i][j];
          word += grid[x1][y1];
          word += grid[x2][y2];
          words.insert(word);
        }
      }
    }
  }

  cout << *words.begin() << endl;

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}


