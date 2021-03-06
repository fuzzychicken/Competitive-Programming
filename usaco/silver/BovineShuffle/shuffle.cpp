#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("shuffle.in","r",stdin);
	freopen("shuffle.out","w",stdout);
	cin >> n;
	vector<int> shifts(n), parent(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> shifts[i];
		shifts[i]--;
		parent[shifts[i]]++;
	}
	int ans = n;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (parent[i] == 0) {
			q.push(i);
			ans--;
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (--parent[shifts[cur]] == 0) {
			q.push(shifts[cur]);
			ans--;
		}
	}
	cout << ans << '\n';
	return 0;
}
