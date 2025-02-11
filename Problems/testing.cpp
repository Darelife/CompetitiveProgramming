// // #include <bits/stdc++.h>
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// // using namespace std;
// // using namespace __gnu_pbds;

// // #define int long long
// // using pii = pair<int, int>;

// // #define forr(i, n) for (int i = 0; i < n; i++)
// // #define reforr(i, n) for (int i = n; i >= 0; i--)
// // #define eqforr(i, a, n) for (int i = a; i <= n; i++)
// // #define sqforr(i, n) for (int i = 1; i * i <= n; i++)
// // #define f(i, a, b) for (int i = a; i < b; i++)
// // #define pba push_back
// // #define popb pop_back
// // #define popf pop_front
// // #define allEle(x) (x).begin(), (x).end()
// // #define allRle(x) (x).rbegin(), (x).rend()

// // typedef vector<int> vint;
// // typedef vector<string> vstr;
// // #define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
// // #define vcin(vint, n) forr(i, n) cin >> vint[i]
// // #define vpin(vint)                                                             \
// //   for (auto x : vint)                                                          \
// //     cout << x << " ";                                                          \
// //   cout << endl;
// // #define vpstr(vstr)                                                            \
// //   for (auto x : vstr)                                                          \
// //     cout << x << " ";                                                          \
// //   cout << endl;

// // const int inf = 1e9 + 5;
// // const int MOD = 1e9 + 7;

// // void solve() {
// //   int n;
// //   cin >> n;
// //   vint a(n);
// //   vcin(a, n);
// //   vint b(n);
// //   vcin(b, n);

// //   set<int> s;
// //   forr(i, n) s.insert(a[i]);



// // }

// // signed main() {
// //   ios::sync_with_stdio(0);
// //   cin.tie(0);
// //   int t = 1;
// //   cin >> t;
// //   for (int i = 0; i < t; i++)
// //     solve();
// // }

// #include <bits/stdc++.h>
// using namespace std;

// // Function to simulate path and get number of turns
// int simulate(int n, vector<int> a, vector<int> b) {
//   int pos = n;  // starting position
//   int turns = 0;

//   while (pos > 0) {
//     // If current position is invalid
//     if (pos > n) return -1;

//     // If frozen at current position
//     if (b[pos - 1] == 1) turns++;

//     // Add turn for jump and update position
//     turns++;
//     pos -= a[pos - 1];

//     // If we fall below ground
//     if (pos < 0) return -1;
//   }

//   return turns;
// }

// int main() {
//   int n;
//   cin >> n; // h == n, so read same value twice

//   vector<int> a(n), b(n);
//   for (int i = 0; i < n; i++) cin >> a[i];
//   for (int i = 0; i < n; i++) cin >> b[i];

//   // Store unique values of a for modification
//   set<int> possible_jumps(a.begin(), a.end());

//   int best_k = -1;      // position to modify
//   int best_x = -1;      // new value for a[k]
//   int best_y = -1;      // new value for b[k]
//   int min_turns = 1e9;  // minimum turns needed

//   // Try modifying each position
//   for (int k = 0; k < n; k++) {
//     // Try each possible jump value (from existing values)
//     for (int new_a : possible_jumps) {
//       // Try both freeze values (0 and 1)
//       for (int new_b = 0; new_b < 2; new_b++) {
//         // Make temporary copy of arrays
//         vector<int> temp_a = a;
//         vector<int> temp_b = b;

//         // Modify position k
//         temp_a[k] = new_a;
//         temp_b[k] = new_b;

//         // Simulate path
//         int turns = simulate(n, temp_a, temp_b);

//         // If valid path and better than current best
//         if (turns != -1 && turns < min_turns) {
//           min_turns = turns;
//           best_k = k + 1;  // convert to 1-based indexing
//           best_x = new_a;
//           best_y = new_b;
//         }
//       }
//     }
//   }

//   // Print result
//   if (best_k == -1) {
//     cout << -1 << endl;
//   } else {
//     cout << best_k << endl;
//     cout << best_x << " " << best_y << endl;
//     cout << min_turns << endl;
//   }

//   return 0;
// }

