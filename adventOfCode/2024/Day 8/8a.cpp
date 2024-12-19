#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
template <typename T, typename V> void __print(const pair<T, V>& x) { cerr << '{';__print(x.first);cerr << ',';__print(x.second); cerr << '}'; }
template <typename T> void __print(const T& x) { int f = 0;cerr << '{';for (auto& i : x)cerr << (f++ ? "," : ""), __print(i);cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t);if (sizeof...(v)) cerr << ", ";_print(v...); }
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

const int inf = 1e9 + 5;
const int MOD = 1e9 + 7;

void smallestPrimefactor(vint& spf, int psize) {
  vint tspf(psize + 1, 1e9);
  tspf[0] = 0;
  tspf[1] = 1;
  vector<bool> isprime(psize + 1, true);
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 2;i <= psize;i++)
  {
    if (isprime[i])
    {
      tspf[i] = i;
      for (int j = i * i;j <= psize;j = j + i)
      {
        isprime[j] = false;
        tspf[j] = min(i, tspf[j]);
      }
    }
  }
  spf = tspf;
}

vector<pair<int, int>> primeFactorization(int x, vector<int>& spf) {
  vector<pair<int, int>> ans;
  while (x != 1)
  {
    int prime = spf[x];
    int cnt = 0;
    while (x % prime == 0)
    {
      cnt++;
      x = x / prime;
    }
    ans.push_back({ prime,cnt });
  }
  return ans;
}

void precomputeprime(vector<bool>& primes, int psize) {
  vector<bool> tvector(psize + 1, true);
  tvector[0] = false;
  tvector[1] = false;
  for (int i = 2;i <= psize;i++)
  {
    if (tvector[i] == true)
    {
      for (int j = i * i;j <= psize;j = j + i)
      {
        tvector[j] = false;
      }
    }
  }
  primes = tvector;
}

int mul(int x, int y, int MOD) {
  return (x % MOD * y % MOD) % MOD;
}

int binpowmod(int x, int y, int mod)
{
  int ans = 1;
  while (y > 0)
  {
    if (y & 1)
    {
      ans = mul(ans, x, mod);
    }
    x = mul(x, x, mod);
    y = y >> 1;
  }
  return ans;
}

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

int modDivide(int x, int y, int mod) // (a/(b*c))%m = (a. b^(m-2) . c^(m-2))%m  ..IF M is not PRIME -> (a/b)%M = (a * (b^(phi(M) - 1)))%M.
{
  return mul(x, binpowmod(y, (mod - 2), mod), mod);
}

int ncr(int n, int r, vint& fact, vint& ifact, int mod = 1e9 + 7)
{
  return mul(fact[n], mul(ifact[r], ifact[n - r], mod), mod); // MOD = 1e9+7 ;
}

struct Pos {
  int x, y;

  Pos operator+(const Pos& other) const {
    return { x + other.x, y + other.y };
  }

  Pos operator-(const Pos& other) const {
    return { x - other.x, y - other.y };
  }

  Pos& operator+=(const Pos& other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  Pos& operator-=(const Pos& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  bool operator==(const Pos& other) const {
    return x == other.x && y == other.y;
  }

  bool operator!=(const Pos& other) const {
    return !(*this == other);
  }
};

struct PosHash {
  size_t operator()(const Pos& pos) const {
    return hash<int>()(pos.x) ^ hash<int>()(pos.y);
  }
};

struct Map {
  int width, height;
  unordered_map<char, vector<Pos>> antennas;

  vector<Pos> find_antinode(const Pos& antenna1, const Pos& antenna2, bool part2) const {
    Pos dist = antenna2 - antenna1;
    vector<Pos> antinodes = { antenna2 + dist, antenna1 - dist };

    if (part2) {
      Pos pos1 = antenna1 - dist;
      Pos pos2 = antenna2 + dist;

      while (is_in_map(pos1)) {
        antinodes.push_back(pos1);
        pos1 -= dist;
      }

      while (is_in_map(pos2)) {
        antinodes.push_back(pos2);
        pos2 += dist;
      }
    }

    return antinodes;
  }

  bool is_in_map(const Pos& pos) const {
    return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
  }
};

Map parse_input(istream& input) {
  vector<string> lines;
  string line;
  while (getline(input, line)) {
    lines.push_back(line);
  }

  int width = lines[0].size();
  int height = lines.size();
  unordered_map<char, vector<Pos>> antennas;

  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      char c = lines[j][i];
      if (c != '.') {
        antennas[c].push_back({ i, height - j - 1 });
      }
    }
  }

  return { width, height, antennas };
}

size_t part1(const Map& map) {
  unordered_set<Pos, PosHash> antinodes;

  for (const auto& [_, antennas] : map.antennas) {
    for (size_t i = 0; i < antennas.size(); ++i) {
      for (size_t j = i + 1; j < antennas.size(); ++j) {
        vector<Pos> anti = map.find_antinode(antennas[i], antennas[j], false);
        antinodes.insert(anti.begin(), anti.end());
      }
    }
  }

  return count_if(antinodes.begin(), antinodes.end(), [&map](const Pos& antinode) {
    return map.is_in_map(antinode);
    });
}

size_t part2(const Map& map) {
  unordered_set<Pos, PosHash> antinodes;

  for (const auto& [_, antennas] : map.antennas) {
    if (antennas.size() > 1) {
      antinodes.insert(antennas.begin(), antennas.end());
    }

    for (size_t i = 0; i < antennas.size(); ++i) {
      for (size_t j = i + 1; j < antennas.size(); ++j) {
        vector<Pos> anti = map.find_antinode(antennas[i], antennas[j], true);
        antinodes.insert(anti.begin(), anti.end());
      }
    }
  }

  return count_if(antinodes.begin(), antinodes.end(), [&map](const Pos& antinode) {
    return map.is_in_map(antinode);
    });
}

void solve() {
  // vector<string> v;
  // for (int i = 0; i < 50; i++) {
  //   string x;
  //   cin >> x;
  //   v.pba(x);
  // }
  ifstream infile("8.txt");
  Map map = parse_input(infile);

  size_t result1 = part1(map);
  cout << "Part 1: " << result1 << endl;

  size_t result2 = part2(map);
  cout << "Part 2: " << result2 << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("8.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // int t = 1;
  // // cin >> t;
  // for (int i = 0; i < t; i++)
  //   solve();
  solve();
}

