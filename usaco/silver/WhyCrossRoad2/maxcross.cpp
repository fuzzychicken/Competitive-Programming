#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("maxcross.in","r",stdin);
	freopen("maxcross.out","w",stdout);
	int n, k, b;
	cin >> n >> k >> b;
	vector<int> loc(n, 0);
	for (int i = 0; i < b; i++) {
		int idx;
		cin >> idx;
		loc[idx-1] = 1;
	}
	int p1 = 0, p2 = k-1, ret = INT_MAX, start_sum = 0;
	for (int i = 0; i < k-1; i++) {
		start_sum += loc[i];
	}
	while (p2 <= n-1) {
		start_sum += (loc[p2] - loc[p1]);
		ret = min(ret, start_sum);
		p1++, p2++;
	}
	cout << ret << '\n';
	return 0;
}
