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

void solve() {
  // cout << 1;
  int n;
  char trump;
  cin >> n >> trump;
  int trum = 0;
  int nontrum = 0;
  vstr cards(2 * n);
  vcstr(cards, 2 * n);
  vint hv, sv, dv, cv;
  // cout << 1;
  map<int, int> h, s, d, c;
  int hc, sc, dc, cc;
  forr(i, 2 * n) {
    if (cards[i][1] == trump)
      trum++;
    else
      nontrum++;
    if (cards[i][1] == 'H') h[cards[i][0] - '0']++, hc++, hv.pba(cards[i][0] - 48);
    else if (cards[i][1] == 'C') c[cards[i][0] - '0']++, cc++, cv.pba(cards[i][0] - 48);
    else if (cards[i][1] == 'D') d[cards[i][0] - '0']++, dc++, dv.pba(cards[i][0] - 48);
    else if (cards[i][1] == 'S') s[cards[i][0] - '0']++, sc++, sv.pba(cards[i][0] - 48);
  }

  map<int, int> aa;
  if (trump == 'H') aa = h;
  else if (trump == 'C') aa = c;
  else if (trump == 'D') aa = d;
  else if (trump == 'S') aa = s;

  vstr hpair, spair, dpair, cpair;
  vint notpaired;
  // HEADS
  // get the median number of the house
  if (trump != 'H') {
    int pairs = 0;
    sort(allEle(hv));
    int i = 0, j = hv.size() - 1;
    while ((i < j) && (hv[i] < hv[j])) {
      hpair.pba(to_string(hv[i]) + " " + to_string(hv[j]));
      i++;
      j--;
      pairs++;
    }
    int hmedian = hv[i];
    if (i > j)
      forr(k, j - i + 1) notpaired.pba(hv[i]);
  }
  if (trump != 'S') {
    int pairs = 0;
    sort(allEle(sv));
    int i = 0, j = sv.size() - 1;
    while ((i < j) && (sv[i] < sv[j])) {
      spair.pba(to_string(sv[i]) + " " + to_string(sv[j]));
      i++;
      j--;
      pairs++;
    }
    int smedian = sv[i];
    if (i > j)
      forr(k, j - i + 1) notpaired.pba(sv[i]);
  }
  if (trump != 'D') {
    int pairs = 0;
    sort(allEle(dv));
    int i = 0, j = dv.size() - 1;
    while ((i < j) && (dv[i] < dv[j])) {
      dpair.pba(to_string(dv[i]) + " " + to_string(dv[j]));
      i++;
      j--;
      pairs++;
    }
    int dmedian = dv[i];
    if (i > j)
      forr(k, j - i + 1) notpaired.pba(dv[i]);
  }
  if (trump != 'C') {
    int pairs = 0;
    sort(allEle(cv));
    int i = 0, j = cv.size() - 1;
    while ((i < j) && (cv[i] < cv[j])) {
      cpair.pba(to_string(cv[i]) + " " + to_string(cv[j]));
      i++;
      j--;
      pairs++;
    }
    int cmedian = cv[i];
    if (i > j)
      forr(k, j - i + 1) notpaired.pba(cv[i]);
  }
  if (notpaired.size() > trum) {
    cout << "IMPOSSIBLE\n";
  } else cout << notpaired.size() << "\n";

  // pair up all the houses
  // pair up the remaining cards with the trump cards
  // pair up the remaining trump cards -> if trump cards < 0 -> IMPOSSIBLE
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    // cout << 1;
    solve();
  }
}