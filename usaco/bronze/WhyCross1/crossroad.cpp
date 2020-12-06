#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("crossroad.in","r",stdin);
	freopen("crossroad.out","w",stdout);
	int n, crossings = 0;
	cin >> n;
	vector<int> prev(10, -1);
	for (int i = 0; i < n; i++) {
		int id, obs;
		cin >> id >> obs;
		id--;
		if (prev[id] == -1) {
			prev[id] = obs;
		}
		else {
			if (prev[id] != obs) {
				crossings++;
			}
			prev[id] = obs;
		}
	}
	cout << crossings << '\n';
	return 0;
}

