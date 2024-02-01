// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;

// #define la(i, n) for (int i = 0; i < n; i++)  // loop around
// #define ela(i, n) for (int i = 0; i < n; i++) // Equal Loop Around
// #define pba push_back
// #define pfa push_front
// #define popb pop_back
// #define popf pop_front
// #define gla(i, a, n) for (int i = a; i < n; i++) // general loop around
// #define empb emplace_back
// #define empf emplace_front
// #define allEle(x) (x).begin(), (x).end()
// #define allRle(x) (x).rbegin(), (x).rend()
// #define sq(x) ((x) * (x))
// #define lasqr(i, n) for (int i = 0; i * i < n; i++) // loop around square
// root #define mpair make_pair #define mtuple make_tuple

// typedef vector<int> vint;
// typedef vector<ll> vill;

// const int nmax = 1e6 + 5;
// const int inf = 1e9 + 5;

// static void solve() {
//   int n, k, q, index;
//   cin >> n >> k >> q;
//   vector<int> a;
//   vector<int> numberOfDays;
//   // numberOfDays.pb(0);
//   int tempp;
//   cin >> tempp;
//   int next = 0;
//   numberOfDays.push_back(q >= tempp);
//   la(i, n - 1) {
//     int temp;
//     cin >> temp;
//     a.push_back(temp);
//     if (temp <= q) {
//       if (next) {
//         numberOfDays.push_back(1);
//       } else {
//         numberOfDays[numberOfDays.size() - 1]++;
//       }
//       next = 0;
//     } else {
//       next = 1;
//       // numberOfDays.push_back(0);
//     }
//   }
//   if (numberOfDays[0] == 0)
//     numberOfDays.erase(numberOfDays.begin());

//   if (numberOfDays.size() == 0) {
//     cout << 0 << endl;
//     return;
//   }
//   // cout << numberOfDays.size() << endl;
//   int aaa = 0;
//   for (auto &i : numberOfDays) {
//     // cout << i << " ";
//     // cout << endl;
//     for (int j = k; j <= i; j++) {
//       aaa += (i + j - 1) / j;
//     }

//     // cout << pow(2, i) - 1 - (k * (k + 1) / 2) << endl;
//   }
//   cout << aaa << endl;

//   // cout << endl;
// }

// signed main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int t = 1;
//   cin >> t;
//   for (int i = 0; i < t; i++)
//     solve();
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int i, int k, int q, vector<int> a) {
  ll v = 0, c = 0;
  for (int t : a) {
    if (t <= q) {
      c++;
    } else {
      c = 0;
    }

    if (c >= k) {
      v += c - k + 1;
    }
  }
  cout << v << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    solve(n, k, q, a);
  }

  return 0;
}