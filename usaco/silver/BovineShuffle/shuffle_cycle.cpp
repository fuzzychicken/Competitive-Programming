#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> shuffles, vis;

void visit(int idx) {
	set<int> used;
	while (vis[idx] == 0) {
		used.insert(idx);
		vis[idx] = 1;
		idx = shuffles[idx];
	}
	if (used.find(idx) != used.end()) {
		int prev = idx;
		bool first = true;
		while (first || idx != prev) {
			vis[idx] = 2;
			idx = shuffles[idx];
			first = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("shuffle.in","r",stdin);
	freopen("shuffle.out","w",stdout);
	cin >> n;
	shuffles.resize(n), vis.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> shuffles[i];
		shuffles[i]--;
	}
	for (int i = 0; i < n; i++) 
		if (vis[i] == 0) 
			visit(i);
	int cnt = 0;
	for (int i = 0; i < n; i++) 
		if (vis[i] == 2) 
			cnt++;
	cout << cnt << '\n';
	return 0;
}