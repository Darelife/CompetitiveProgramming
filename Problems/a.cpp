// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//   int t;
//   cin >> t;
//   while (t--)
//   {
//     int n;
//     cin >> n;
//     long long a[n];
//     for (auto& i : a) cin >> i;

//     int common = 2;
//     while (true) {
//       int breakkk = 0;
//       for (int i = 0; i < n - 1; i++) {
//         // unordered_set <int> s;
//         // for (auto num : a) {
//         //   s.insert(num & (1LL << i));
//         // }

//         if (a[i] % common != a[i + 1] % common) {
//           cout << (common) << endl;
//           breakkk = 1;
//           break;
//         }

//         // if (s.size() == 2) { break; } else { common *= 2; }
//       }
//       common *= 2;
//       if (breakkk) { break; }
//     }
//     // cout << (common) << endl;
//   }
// }

#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    long long a[n];
    for (auto& i : a) cin >> i;

    int common = 0;
    for (int i = 0; i < 64; i++) {
      unordered_set <long long> s;
      for (auto num : a) {
        s.insert(num & (1LL << i));
      }

      if (s.size() == 2) { break; } else { common++; }
    }
    cout << (1LL << (common + 1)) << endl;
  }
}