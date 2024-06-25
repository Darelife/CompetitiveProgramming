#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;
  
// position is a function which takes in a char and returns the position of that char in the vector
int position(char a, vector<char> v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == a) {
      return i;
    }
  }
  return -1;
}

void testcase() {
  // a 3x3 grid using 2d vectors
  // save the coordinates as well as the character in the grid
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
}