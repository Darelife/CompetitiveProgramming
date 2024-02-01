// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// void printvec(vector<int> a) {
//   for (int i = 0; i < a.size(); i++) {
//     cout << a[i] << " ";
//   }
//   cout << endl;
// }

// bool is_palindrome(string s) {
//   for (int i = 0; i < s.size() / 2; i++) {
//     if (s[i] != s[s.size() - 1 - i]) {
//       return false;
//     }
//   }
//   return true;
// }

// void solve(int n, int k, string s) {
//   if (n - k == 1) {
//     cout << "YES" << endl;
//     return;
//   }
//   map<char, int> m;
//   for (int i = 0; i < n; i++) {
//     m[s[i]]++;
//   }
//   if (k == 0) {
//     if (is_palindrome(s)) {
//       cout << "YES" << endl;
//     } else {
//       cout << "NO" << endl;
//     }
//     return;
//   }
//   int count = 0;
//   for (auto x : m) {
//     if (x.second % 2 == 1) {
//       count += 1;
//     }
//   }
//   if ((n - k) % 2 == 0) {
//     if (count == k) {
//       cout << "yes" << count << endl;
//     } else {
//       cout << "no" << count << endl;
//     }
//   } else {
//     if (count - 1 == k) {
//       cout << "YES" << count << endl;
//     } else {
//       cout << "NO" << count << endl;
//     }
//   }
// }
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   int t = 1;
//   cin >> t;
//   while (t--) {
//     int n, k;
//     cin >> n >> k;
//     string s;
//     cin >> s;
//     solve(n, k, s);
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void printvec(vector<int> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void print(auto a) { cout << a << endl; }

void solve(int n, int k, string s) {
  int count = 0;
  map<char, int> m;
  for (auto x : s) {
    m[x]++;
  }
  for (auto x : m) {
    if (x.second % 2 == 1)
      count++;
  }
  if (count <= k + 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    solve(n, k, s);
  }
  return 0;
}