#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("maxcross.in","r",stdin);
	freopen("maxcross.out","w",stdout);
	int n, k, b;
	cin >> n >> k >> b;
	vector<int> loc(n, 0), prefix(n);
	for (int i = 0; i < b; i++) {
		int idx;
		cin >> idx;
		loc[idx-1] = 1;
	}
	prefix[0] = loc[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i-1] + loc[i];
	}
	int p1 = 0, p2 = k-1, ret = INT_MAX;
	while (p2 <= n-1) {
		ret = min(ret, prefix[p2] - prefix[p1]);
		p1++, p2++;
	}
	cout << ret << '\n';
	return 0;
}
