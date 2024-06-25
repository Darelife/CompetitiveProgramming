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


const int inf = 1e9 + 5;

int digitSum(int n) {
  if (n < 10) return n;
  return n % 10 + digitSum(n / 10);
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool zero = false;
  forr(i, n) {
    if (s[i] == '0') {
      zero = true;
      if (n > 3) {
        cout << 0 << endl;
        return;
      }
    }
  }
  if (n == 2) {
    cout << (s[0] - '0') * 10 + s[1] - '0' << endl;
    return;
  }
  if (n == 1) {
    cout << s[0] - '0' << endl;
    return;
  }
  if (zero == true && n == 3) {
    if (s[0] == '0' || s[2] == '0') {
      cout << 0 << endl;
      return;
    } else {
      int aaa = s[0] - '0';
      int bbb = s[2] - '0';
      cout << min(aaa * bbb, aaa + bbb) << endl;
      return;
    }
  }

  // // FUCKKK -> it was supposed to be small2, and smalli
  // int large2 = 100;
  // int largei = -1;
  // for (int i = 0; i < n - 1; i++) {
  //   int a = (s[i] - '0') * 10 + (s[i + 1] - '0');
  //   large2 = min(large2, a);
  //   if (large2 == a) largei = i;
  // }
  // int sum = 0;
  // forr(i, n) {
  //   sum += s[i] - '0';
  // }
  // int summ = sum;
  // // sum - sum of large2's digits + large2
  // sum -= s[largei] - '0';
  // sum -= s[largei + 1] - '0';
  // sum += large2;
  // // cout << sum << endl;
  // // for -> i = 0 -> n-2;
  // // check s[i], s[i+1], s[i+2] -> if 1 is in s[i], or s[i+2] -> store the number
  // int val = inf;
  // int vali = -1;
  // for (int i = 0; i < n - 2; i++) {
  //   int a = s[i] - '0';
  //   int b = s[i + 1] - '0';
  //   int c = s[i + 2] - '0';
  //   if (a == 1) {
  //     int t = b * 10 + c;
  //     val = min(t, val);
  //     if (val == t) {
  //       vali = i + 1;
  //     }
  //   }
  //   if (c == 1) {
  //     int t = a * 10 + b;
  //     val = min(t, val);
  //     if (val == t) {
  //       vali = i;
  //     }
  //   }
  // }
  // summ -= (s[vali] - '0');
  // summ -= 1;
  // summ += val;
  // cout << min(sum, summ) << endl;
  int ans = inf;
  forr(i, n - 1) {
    vint val;

    forr(j, n) {
      if (j == i) {
        val.pba((s[j] - '0') * 10 + (s[j + 1] - '0'));
        ++j;
      } else {
        val.pba(s[j] - '0');
      }
    }


    int sum = val[0] == 1 ? 0 : val[0];
    for (int k = 1; k < val.size(); ++k) {
      if (val[k] != 1) {
        sum += val[k];
      }
    }

    // Update the answer if a new minimum sum is found
    ans = min(ans, sum);
  }

  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}