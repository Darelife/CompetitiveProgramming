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
  // int n, l;
  // cin >> n >> l;
  // vector<string> v;
  // int fuckAi = 0;
  // int letter = 0;
  // int cool = 0;
  // forr(i, n) {
  //   string s;
  //   cin >> s;

  //   char tempLetter = letter;
  //   int tempA = 0, tempC = 0;

  //   forr(j, s.length()) {
  //     char c;
  //     if (letter == 0) c = 'n';
  //     else if (letter == 1) c = 'a';
  //     else if (letter = 2) c = 'r';
  //     else if (letter = 3) c = 'e';
  //     else if (letter = 4) c = 'k';

  //     if (s[j] == c) {
  //       letter = (letter + 1) % 5;
  //       tempC += 5;
  //     } else if ((s[j] == 'n' || s[j] == 'a' || s[j] == 'r' || s[j] == 'e' || s[j] == 'k')) {
  //       tempA++;
  //     }
  //   }
  //   if (tempC > tempA) {
  //     v.pba(s);
  //   } else {
  //     letter = tempLetter;
  //   }
  // }
  // debug(v);
  int n, m;
  cin >> n >> m;
  vector<string> strings(n);
  for (int i = 0; i < n; i++) {
    cin >> strings[i];
  }

  int ans = LLONG_MIN;

  for (int i = 0; i < (1 << n); i++) {
    string s = "";
    // this thing basically generates all possible sols
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        s += strings[j];
      }
    }

    int cool = 0, fuckAi = 0;
    int letter = 0;
    vector<char> meee = { 'n', 'a', 'r', 'e', 'k' };
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if (c == meee[letter]) {
        letter = (letter + 1) % 5;
        if (letter == 0) {
          cool += 5;
        }
      } else if (c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k') {
        fuckAi++;
      }
    }

    for (int i = 0; i < letter; i++) {
      fuckAi++;
    }

    ans = max(ans, cool - fuckAi);
    // ans = max(ans, 0LL);
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}