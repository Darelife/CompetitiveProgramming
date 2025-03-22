#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> val, val1;
vector<vector<char>> parent;
vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<char> dirSymbols = { 'U', 'D', 'L', 'R' };
vector<vector<char>> pos;

void bfs(queue<pair<int, int>>& q, vector<vector<int>>& val, bool trackParent = false) {
	int n = pos.size(), m = pos[0].size();

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		int x = curr.first, y = curr.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + directions[i].first, ny = y + directions[i].second;

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && pos[nx][ny] != '#' && val[nx][ny] == LLONG_MAX) {
				val[nx][ny] = val[x][y] + 1;
				if (trackParent) parent[nx][ny] = dirSymbols[i];
				q.push({ nx, ny });
			}
		}
	}
}

int32_t main() {
	int n, m;
	cin >> n >> m;

	pos.resize(n, vector<char>(m));
	val.resize(n, vector<int>(m, LLONG_MAX));
	val1.resize(n, vector<int>(m, LLONG_MAX));
	parent.resize(n, vector<char>(m, ' '));

	queue<pair<int, int>> monsterQueue, personQueue;
	pair<int, int> start;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pos[i][j];
			if (pos[i][j] == 'M') {
				monsterQueue.push({ i, j });
				val[i][j] = 0;
			} else if (pos[i][j] == 'A') {
				start = { i, j };
				val1[i][j] = 0;
				personQueue.push({ i, j });
			}
		}
	}

	bfs(monsterQueue, val);
	bfs(personQueue, val1, true);

	pair<int, int> escapePos = { -1, -1 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (val1[i][j] != LLONG_MAX && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
				if (val1[i][j] < val[i][j]) {
					escapePos = { i, j };
					break;
				}
			}
		}
		if (escapePos.first != -1) break;
	}

	if (escapePos.first == -1) {
		cout << "NO" << endl;
		return 0;
	}

	string path;
	pair<int, int> curr = escapePos, src = start;

	while (curr != src) {
		char move = parent[curr.first][curr.second];
		path += move;
		if (move == 'U') curr.first++;
		else if (move == 'D') curr.first--;
		else if (move == 'L') curr.second++;
		else if (move == 'R') curr.second--;
	}

	reverse(path.begin(), path.end());

	cout << "YES" << endl;
	cout << path.size() << endl;
	cout << path << endl;

	return 0;
}
