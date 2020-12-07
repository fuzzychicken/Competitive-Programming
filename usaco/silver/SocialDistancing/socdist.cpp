#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int64_t, int64_t>> grass;

bool check(int64_t a) {
	int64_t cnt = 0;
	int64_t curloc = -1 * 1e18;
	for (int i = 0; i < m; i++) {
		while (max(curloc + a, grass[i].first) <= grass[i].second) {
			curloc = max(curloc + a, grass[i].first);
			cnt++;
			if (cnt >= n) break;
		}
		if (cnt >= n) break;
	}
	return cnt >= n;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	freopen("socdist.in","r",stdin);
	freopen("socdist.out","w",stdout);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int64_t a, b;
		cin >> a >> b;
		grass.push_back({a, b});
	}

	sort(grass.begin(), grass.end());

	int64_t res = -1;
	int64_t lo = 1, hi = 1e18+10;
	
	while (lo <= hi) {
		int64_t mid = (lo+hi) / 2;
		if (check(mid)) {
			res = mid;
			lo = mid + 1;
		} else {
			hi = mid-1;
		}
	}

	cout << res << '\n';
	return 0;
}