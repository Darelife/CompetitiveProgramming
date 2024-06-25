#include <bits/stdc++.h>
using namespace std;

#define ll long long

void printvec(vector<ll> a) {
  for (ll i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void print(auto a) { cout << a << endl; }

void printmap(map<ll, ll> mp) {
  for (auto i : mp) {
    cout << i.first << " " << i.second << endl;
  }
}

string bool_to_string(bool b) { return b ? "YES" : "NO"; }

string solve(ll n, ll k, vector<ll> c, map<ll, ll> mp) {
  // bool ans = false;
  // if (mp[data[n - 1]]%k==0 && mp[data[n - 1]] > 0) {
  //   ans = true;
  //   return bool_to_string(ans);
  // }
  // if (mp[data[n - 1]] < k) {
  //   ans = false;
  //   return bool_to_string(ans);
  // }
  // for (auto i : mp) {
  //   if (i.second == k && data[n - 1] != i.first) {
  //     ans = true;
  //     return bool_to_string(ans);
  //   }
  // }
  // if (k == 1) {
  //   ans = true;
  //   return bool_to_string(ans);
  // }
  // return bool_to_string(ans);
  int left = 0, right = 0, i = 0, j = n -  1;
  int k_left = k, k_right = k;

  if (c[0] == c[n - 1]) {
    k_left = k / 2;
    k_right = k - k_left;
  }
  for (; i < n && left < k_left; i++) {
    if (c[i] == c[0])
      left++;
  }
  for (; j >= 0 && right < k_right; j--) {
    if (c[j] == c[n - 1])
      right++;
  }
  return bool_to_string((i - 1) < (j + 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--) {
    vector<ll> data;
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
      ll temp;
      cin >> temp;
      data.push_back(temp);
      mp[temp] += 1;
    }
    // printmap(mp);
    // print("\n");
    cout << solve(n, k, data, mp) << endl;
  }
  return 0;
}