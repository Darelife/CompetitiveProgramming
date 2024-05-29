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

const int inf = 1e9 + 5;

void printarr(vint arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}


// int works(vint arr, int n, int mid) {
//   int ind = -1;
//   forr(i, n) {
//     if (arr[i] == mid) {
//       ind = i;
//       break;
//     }
//   }
//   vint temp = { mid };
//   for (int i = ind + 1; i < n; i++) {
//     temp.pba(arr[i]);
//     sort(allEle(temp));
//     if (temp[(temp.size() - 1) / 2] == mid) return 1;
//   }
//   // WTFFF

//   // ATTEMPT 2
//   temp = { mid };
//   for (int i = ind - 1;i >= 0;i--) {
//     temp.pba(arr[i]);
//     sort(allEle(temp));
//     if (temp[(temp.size() - 1) / 2] == mid)return true;
//   }

//   // ATTEMPT 3
//   temp = {};
//   temp.pba(mid);
//   for (int i = 1;ind + i<n && ind - i >-1;i++) {
//     temp.pba(arr[i]);
//     sort(allEle(temp));
//     if (temp[(temp.size() - 1) / 2] == mid)return true;
//   }
//   return false;
// }
// void solve() {
//   // cout << "------------" << endl;

//   // int n;
//   // cin >> n;

//   // if (n == 1) {
//   //   cout << 0 << endl;
//   //   return;
//   // }

//   // vint arr(n);
//   // vcin(arr, n);
//   // if (n == 2 && arr[0] != arr[1]) {
//   //   cout << 1 << endl;
//   //   return;
//   // }
//   // if (n == 2 && arr[0] == arr[1]) {
//   //   cout << 0 << endl;
//   //   return;
//   // }

//   // int ans = -1;
//   // int last = arr[0];
//   // int rowLength = 1;
//   // for (int i = 0; i < n; i++) {
//   //   if ((i >= 1) && arr[i] != last && arr[i - 1] == last) {
//   //     cout << i << endl;
//   //     ans += rowLength;
//   //     arr[i] = (arr[i] + arr[i - 1]) / 2;
//   //     if (arr[i - 1] == arr[i]) {
//   //       rowLength++;
//   //     } else {
//   //       arr[i - 1] = arr[i];
//   //       rowLength = 1;
//   //     }
//   //     last = arr[i];
//   //   } else {
//   //     rowLength++;
//   //     last = arr[i];
//   //   }
//   //   printarr(arr);
//   // }

//   // cout << "------------ ";
//   // cout << ans << endl;
//   int n;
//   cin >> n;
//   vint arr(n);
//   vcin(arr, n);
//   int s = (-1) * inf;
//   int l = inf;
//   for (int& x : arr) {
//     l = max(l, x);
//     s = min(s, x);
//   }
//   int ans = -1;
//   int mid;

//   // binary search ig....idk what to do!!!!! HELPPPPP ALGO GODS!!!!
//   while (s < l + 1) {
//     mid = s + (l - s) / 2;
//     // x in thermo
//     // i think i figured it out finally!!!! why tf am i documenting this??
//     if (works(arr, n, mid)) {
//       ans = mid;
//       s = mid + 1;
//     } else l = mid - 1;
//   }
//   cout << ans << endl;
// }
vint arr;
bool works(int t) {
  // mini is the minimum value of last
  int mini = 0, x, last = 0;
  if (arr[0] >= t)
    x = 1;
  else
    x = -1;
  for (int i = 1; i < arr.size(); i++) {
    mini = min(mini, last);
    last = x;
    if (arr[i] >= t)
      x++;
    else
      x--;
    if (x - mini > 0)
      return true;
  }
  return false;
}
// if works return true -> (no. of elements >= t) is greater than (no. of elements < t)

// finding the median using binary search
void solve() {
  int n;
  cin >> n;
  arr.assign(n, 0);
  vcin(arr, n);
  int l = -1, r = 1e9 + 1;
  while (r > l + 1) {
    int m = (l + r) / 2;
    if (works(m))
      l = m;
    else
      r = m;
    // cout << l << " " << r << endl;
  }
  cout << l << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}