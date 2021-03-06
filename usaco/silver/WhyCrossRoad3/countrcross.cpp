#include <bits/stdc++.h>
using namespace std;

int n, k, r;
set<pair<int, int>> roads[100][100];
vector<pair<int, int>> cows;
bool visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool withinBounds(int x, int y) {
	return (x <= n - 1 && x >= 0 && y <= n - 1 && y >= 0);
}

bool can(pair<int, int> a, pair<int, int> b) {
	memset(visited, false, sizeof(visited));
	int i = a.first, j = a.second;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = true;
	while(!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = v.first + dx[i];
			int y = v.second + dy[i];
			if (withinBounds(x, y) && !visited[x][y] && (roads[v.first][v.second].find(make_pair(x, y)) == roads[v.first][v.second].end())) {
				if (x == b.first && y == b.second) return true;
				q.push(make_pair(x, y));
				visited[x][y] = true;
			} 
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("countcross.in","r",stdin);
	freopen("countcross.out","w",stdout);
	cin >> n >> k >> r;
	for (int i = 0; i < r; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--, c1--, r2--, c2--;
		roads[r1][c1].insert(make_pair(r2, c2));
		roads[r2][c2].insert(make_pair(r1, c1));
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cows.push_back(make_pair(a, b));
	}
	int cnt = 0;
	for (auto i : cows) {
		for (auto j : cows) {
			if (j <= i) continue;
			if (!can(i, j)) { 
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
