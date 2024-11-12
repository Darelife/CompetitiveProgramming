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

void solve() {
  int n;
  cin >> n;
  char trump;
  cin >> trump;

  string suites = "SHDC";
  int t = suites.find(trump);
  vector<int> cards[4];
  for (int i = 0; i < 2 * n; i++)
  {
    string s;
    cin >> s;
    cards[suites.find(s[1])].push_back(s[0]);
  }
  vector<string> ans;
  vector<string> left;

  forr(i, 4) {
    sort(allEle(cards[i]));
    if (i == t) continue;
    // odd size
    if (cards[i].size() % 2 == 1) {
      int x = cards[i].back();
      left.pba(string() + (char)x + suites[i]); // learnt a new thing here....we need to use string() + char
      cards[i].pop_back();
    }
    forr(j, cards[i].size()) {
      int x = cards[i][j];
      ans.pba(string() + (char)x + suites[i]);
    }
  }
  if (left.size() > cards[t].size()) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  for (string s : left) {
    ans.pba(s);
    ans.pba(string() + (char)cards[t].back() + trump);
    cards[t].pop_back();
  }
  for (int j = 0; j < cards[t].size(); j++)
  {
    int x = cards[t][j];
    ans.pba(string() + (char)x + suites[t]);
  }
  debug(ans);
  forr(i, n) {
    cout << ans[2 * i] << " " << ans[2 * i + 1] << endl;
  }


  // vector<string> cards(2 * n);
  // map<char, int> mp;
  // forr(i, 2 * n) { 
  //   cin >> cards[i];

  // }
  // sort(allEle(cards), [&](string a, string b) {if (a[1] == trump && b[1] != trump) return true;if (a[1] != trump && b[1] == trump) return false;if (a[1] == trump && b[1] == trump) return a[0] < b[0];return false;});
  // // 1. Trump Suit
  // // 2. Sort by Non-Trump Suit
  // // 3. Sort by Number
  // debug(cards);

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}