#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

// 10^18 is the maximum query range. 
// We cap lengths at slightly above that to prevent long long overflow.
const ll INF = 2e18;
const int MAX_K = 100;

ll len[MAX_K + 1];
ll total_cnt[MAX_K + 1][26];
int prefX[26][10005];
int prefY[26][10005];

// Recursive function to find count of char 'c' in first 'p' chars of Sk
ll query(int k, ll p, int c) {
  if (p <= 0) return 0;
  if (p >= len[k]) return total_cnt[k][c];
  if (k == 1) return prefX[c][p];
  if (k == 2) return prefY[c][p];

  // Recurrence: Sk = Sk-1 + Sk-2
  if (p <= len[k - 1]) {
    return query(k - 1, p, c);
  } else {
    return total_cnt[k - 1][c] + query(k - 2, p - len[k - 1], c);
  }
}

int main() {
  // Optimize I/O
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string X, Y;
  if (!(cin >> X >> Y)) return 0;

  int nX = X.length();
  int nY = Y.length();

  // 1. Precompute prefix sums for base strings X (S1) and Y (S2)
  for (int j = 0; j < 26; ++j) {
    for (int i = 1; i <= nX; ++i) {
      prefX[j][i] = prefX[j][i - 1] + (X[i - 1] == (char)('a' + j));
    }
    for (int i = 1; i <= nY; ++i) {
      prefY[j][i] = prefY[j][i - 1] + (Y[i - 1] == (char)('a' + j));
    }
  }

  // 2. Precompute lengths and total character counts for S1 to S100
  len[1] = nX;
  len[2] = nY;
  for (int j = 0; j < 26; ++j) {
    total_cnt[1][j] = prefX[j][nX];
    total_cnt[2][j] = prefY[j][nY];
  }

  for (int i = 3; i <= MAX_K; ++i) {
    len[i] = min(INF, len[i - 1] + len[i - 2]);
    for (int j = 0; j < 26; ++j) {
      total_cnt[i][j] = total_cnt[i - 1][j] + total_cnt[i - 2][j];
      // Cap character counts as well to avoid overflow (not strictly necessary with 2e18 cap)
      if (total_cnt[i][j] > INF) total_cnt[i][j] = INF;
    }
  }

  // 3. Process Queries
  int Q;
  cin >> Q;
  while (Q--) {
    ll L, R;
    char C;
    cin >> L >> R >> C;
    int charIdx = C - 'a';
    // Count in range [L, R] is Count(R) - Count(L-1)
    ll result = query(MAX_K, R, charIdx) - query(MAX_K, L - 1, charIdx);
    cout << result << "\n";
  }

  return 0;
}