#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> cows;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cows.push_back(make_pair(b,a));
	}
	sort(cows.begin(), cows.end());
	int p1 = 0, p2 = cows.size()-1;
	long long ans = 0;
	while (p1 < p2) {
		long long sum = cows[p1].first + cows[p2].first;
		int sub = min(cows[p1].second, cows[p2].second);
		cows[p1].second -= sub, cows[p2].second -= sub;
		if (cows[p1].second == 0) p1++;
		if (cows[p2].second == 0) p2--;
		ans = max(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}

