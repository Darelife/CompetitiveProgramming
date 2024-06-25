#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define la(i, n) for (int i = 0; i < n; i++)  // loop around
#define ela(i, n) for (int i = 0; i < n; i++) // Equal Loop Around
#define pba push_back
#define pfa push_front
#define popb pop_back
#define popf pop_front
#define gla(i, a, n) for (int i = a; i < n; i++) // general loop around
#define empb emplace_back
#define empf emplace_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()
#define sq(x) ((x) * (x))
#define lasqr(i, n) for (int i = 0; i * i < n; i++) // loop around square root
#define mpair make_pair
#define mtuple make_tuple

typedef vector<int> vint;
typedef vector<ll> vill;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void solve() {
  // int minEle = inf;
  // int oneOne = 0;
  // la(i, n) {
  //   cin >> arr[i];
  //   minEle = min(minEle, arr[i]);
  //   if (arr[i] == 1 && oneOne == 0) {
  //     oneOne = 1;
  //   } else if (arr[i] == 1 && oneOne == 1) {
  //     cout << "NO" << endl;
  //     oneOne = 2;
  //     return;
  //   }
  // }
  // cout << minEle;
  // int flagDivByMin = 1;
  // la(i, n) {
  //   if (arr[i] % minEle != 0) {
  //     flagDivByMin = 0;
  //     break;
  //   }
  // }
  // if (flagDivByMin && (oneOne != 2)) {
  //   cout << "NO" << endl;
  //   return;
  // } else {
  //   cout << "YES" << endl;
  // }
  // // else {
  // // cout << "NO" << endl;
  // // }
  ll n;
  cin >> n;
  vector<ll> arr(n);

  ll smallestElement = inf;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    smallestElement = min(smallestElement, arr[i]);
  }

  ll countOfSmallest = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == smallestElement) {
      countOfSmallest++;
    }
  }
  if (countOfSmallest == n) {
    cout << "NO" << endl;
    return;
  }

  if (countOfSmallest == 1) {
    cout << "YES" << endl;
    return;
  }

  bool remainderExists = true;
  for (int i = 0; i < n; i++) {
    if (arr[i] != smallestElement && arr[i] % smallestElement != 0) {
      remainderExists = false;
      break;
    }
  }

  if (remainderExists) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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