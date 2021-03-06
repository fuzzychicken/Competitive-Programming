#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int n, m;
vector<pair<ll, ll>> grass;

bool check(ll a) {
	ll cnt = 0;
	ll curloc = -1 * 1e18;
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
	cin.tie(0)->sync_with_stdio(0);
	freopen("socdist.in","r",stdin);
	freopen("socdist.out","w",stdout);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		grass.push_back({a,b});
	}

	sort(grass.begin(), grass.end());

	ll res = -1;
	ll lo = 1, hi = 1e18+10;
	
	while (lo <= hi) {
		ll mid = (lo+hi) / 2;
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
