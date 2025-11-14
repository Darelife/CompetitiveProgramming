#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> parent;
int find(int x) {
  if (parent[x] != x) {
    parent[x] = find(parent[x]);
  }
  return parent[x];
}

void merge(int x, int y) {
  int rootX = find(x);
  int rootY = find(y);
  if (rootX != rootY) {
    if (rootX < rootY) {
      parent[rootY] = rootX;
    } else {
      parent[rootX] = rootY;
    }
  }
}

bool dist(pair<int,int> a, pair<int,int> b, int p) {
  return (b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second) <= p;
}
  
bool check(vector<pair<int,int>>&a, int mid) {
  for (int i = 0;i<n; i++) parent[i] = i;
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      if (dist(a[i], a[j], mid)) merge(i, j);
    }
  }
  for (int i = 0; i<n; i++) if (find(i) != 0) return false;
  return true;
}

int main() {
   cin >> n;
   parent.resize(n);
   for (int i = 0; i<n; i++) parent[i] = i;
   vector<pair<int,int>> a(n);
   for (int i = 0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
   }

   int l = 0, r= 1e9, ans = -1;
   while (l<=r) {
    int mid = l + (r-l)/2;
    if (check(a,mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
   }
   cout << ans << endl;
}