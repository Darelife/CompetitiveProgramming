#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define input(arr, n) for (int i = 0; i < n; i++) cin >> arr[i];
#define print(arr) for (auto i : arr) cout << i << " "; cout << endl;

const int MOD = 1e9 + 7;
int low, high;

class DSU {
public:
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 1; i < n; i++) {
      parent[i] = i;
    }
  }
  int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
  }
  void unionBySize(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    if (pu == pv) return;
    if (size[pu] < size[pv]) {
      parent[pu] = pv;
      size[pv] += size[pu];
    } else {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
};

int binIdx(vector<int>& v, int n, int m, int elem) {
  int low = 0;
  int high = n - 1;

  int ans = m;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (v[mid] >= elem) {
      ans = v[mid];
      high = mid - 1;
    } else low = mid + 1;
  }

  return ans;
}

// int mex(vector<int>& v, int n, int l) {
//     int idx = binIdx(v, n, l);
//     int low = idx;
//     // cout << low << " " << n << endl;
//     int high = n - 1; 
//     int x = v[low];

//     // cout << low << " " << high << " " << x<< endl;

//     int ans = v[high] + 1;
//     while (low <= high) {
//         int mid = low + (high - low) / 2;

//         if (v[mid] - x == mid - idx) low = mid + 1;
//         else {
//             ans = mid - idx;
//             high = mid - 1;
//         }
//     }

//     return ans + x;
// }

ll gcdF(ll a, ll b) {
  if (b == 0) return a;
  return gcdF(b, a % b);
}

ll lcmF(ll a, ll b) {
  return (a * b) / gcdF(a, b);
}


bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

vector<ll> bitArray(ll n) {
  vector<ll> ans(32, 0);
  for (int i = 0; i < 32; i++) {
    if (n & (1LL << i)) ans[i] = 1;
  }
  return ans;
}


void factors(ll n, set<ll>& f) {
  for (int i = 2; i * i <= n && f.size() < 2; i++) {
    if (n % i == 0) {
      f.insert(i);
      n /= i;
    }
  }
}

vector<ll> fact;

bool check(int m, int mid, vector<int>& curr, vector<int>& tot) {
  for (int i = 0; i < 26; i++) {
    if ((m - mid) * (tot[i] - curr[i]) < curr[i]) return false;
  }

  return true;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> v(n);
  vector<int> tot(26, 0);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (auto j : v[i]) tot[j - 'A']++;
  }


  for (auto word : v) {
    vector<int> curr(26, 0);

    for (auto j : word) curr[j - 'A']++;

    int low = 0;
    int high = m;
    int ans = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (check(m, mid, curr, tot)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    cout << ans << " ";
  }

  cout << endl;
}


int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // fact.resize(200001, 0);
  // fact[0] = 1;
  // fact[1] = 1;

  // for (int i = 2; i <= 200000; i++) {
  //     fact[i] = fact[i - 1] * i;
  //     fact[i] %= MOD;
  // }

  // for (int i = 0; i <= 10; i++) cout << fact[i] << " ";
  // cout << endl;

  // int t;
  // cin >> t;
  // while (t--) {
  //     solve();
  // }

  solve();

  // cout << "here" << endl;

  return 0;
}