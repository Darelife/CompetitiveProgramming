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

const int inf = 1e9 + 5;

void solve() {
  // // cout << "------------" << endl;
  // int n;
  // cin >> n;
  // vint arr(n + 2);
  // map<int, int> hash;
  // forr(i, n + 2) {
  //   cin >> arr[i];
  //   hash[arr[i]]++;
  // }

  // sort(allEle(arr));

  // int sum1 = arr[n], sum2 = arr[n + 1];
  // // it could be either of the last 2 elements....what if x is the largest
  // // element, and even greater than the sum of all other elements

  // int sum = 0;
  // forr(i, n + 2) sum += arr[i];

  // // assume for now that the largest element is the sum of all other
  // elements,
  // // and couldn't be x
  // // cout << sum << " " << sum1 << " " << sum2 << endl;
  // if (sum > (2 * sum1 + sum2) && sum > (2 * sum2 + sum1)) {
  //   cout << -1 << endl;
  //   return;
  // } else if (hash.count(sum - 2 * sum2)) {
  //   int x = sum - 2 * sum2;
  //   // print everything except x, and sum2
  //   int flagx = 0, flagsum2 = 0;
  //   forr(i, n + 2) {
  //     if (arr[i] == x && !flagx) {
  //       flagx = 1;
  //       continue;
  //     }
  //     if (arr[i] == sum2 && !flagsum2) {
  //       flagsum2 = 1;
  //       continue;
  //     }
  //     cout << arr[i] << " ";
  //   }
  //   cout << endl;
  // }
  // // assume that the 2nd largest element is the sum of all other elements,
  // and
  // // the largest element is x
  // else if (hash.count(sum - 2 * sum1)) {
  //   int x = sum2;
  //   // print everything except x, and sum1, ie. the first n elements
  //   forr(i, n) cout << arr[i] << " ";
  //   cout << endl;
  // } else {
  //   cout << -1 << endl;
  // }
  int n;
  cin >> n;
  vint a(n + 2);
  map<int, int> hash;
  int sum = 0;
  forr(i, n + 2) {
    cin >> a[i];
    hash[a[i]]++;
    sum += a[i];
  }

  sort(allEle(a));
  int x, sumA, sumB;
  // Case 1 sumA = a[n+1]....then, x = sum - 2*sumA...if it exists
  if (hash.count(sum - 2 * a[n + 1])) {
    if (sum - 2 * a[n + 1] == a[n + 1] && hash[a[n + 1]] == 1) {
      cout << -1 << endl;
      return;
    }
    int flag = 0;
    x = sum - 2 * a[n + 1];
    for (int i = 0; i < n + 1; i++) {
      if (a[i] == x && !flag) {
        flag = 1;
        continue;
      }
      cout << a[i] << " ";
    }
    cout << endl;
  }
  // Case 1, sumA = a[n]....then, x = a[n+1]
  else if (sum == 2 * a[n] + a[n + 1]) {
    x = a[n + 1];
    sumA = a[n];
    forr(i, n) cout << a[i] << " ";
    cout << endl;
  }
  // if (sumB - sumA - x > 0) return -1;
  else {
    cout << -1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}