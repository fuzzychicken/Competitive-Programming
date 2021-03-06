#include <bits/stdc++.h>
using namespace std;

struct store {
	int64_t q, p;
};

int n, m, r;
vector<int64_t> c, rentals;
vector<store> stores;
int64_t possible[100002][2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("rental.in","r",stdin);
	freopen("rental.out","w",stdout);
	cin >> n >> m >> r;
	c.resize(n), stores.resize(m), rentals.resize(r);
	for (int i = 0; i < n; i++) 
		cin >> c[i];
	for (int i = 0; i < m; i++) 
		cin >> stores[i].q >> stores[i].p;
	for (int i = 0; i < r; i++) 
		cin >> rentals[i];
	sort(c.begin(), c.end(), [](int64_t a, int64_t b) {
		return a > b;
	});
	sort(stores.begin(), stores.end(), [](store a, store b) {
		return a.p > b.p;
	});
	sort(rentals.begin(), rentals.end(), [](int64_t a, int64_t b) {
		return a > b;
	});
	int cowidx = 0, storeidx = 0;
	int64_t ans = 0;
	while (storeidx < m && cowidx < n) {
		if (c[cowidx] < stores[storeidx].q) {
			possible[cowidx][0] += c[cowidx] * stores[storeidx].p;
			stores[storeidx].q -= c[cowidx];
			c[cowidx] = 0;
			cowidx++;
		} else if (c[cowidx] > stores[storeidx].q) {
			possible[cowidx][0] += stores[storeidx].q * stores[storeidx].p;
			c[cowidx] -= stores[storeidx].q;
			stores[storeidx].q = 0;
			storeidx++;
		} else {
			possible[cowidx][0] += stores[storeidx].q * stores[storeidx].p;
			c[cowidx] = 0;
			stores[storeidx].q = 0;
			cowidx++;
			storeidx++;
		}
	}
	int ridx = 0;
	for (int i = n-1; i >= 0; i--) {
		if (ridx >= r) possible[i][1] = 0;
		else possible[i][1] = rentals[ridx];
		ridx++;
		ans += max(possible[i][0], possible[i][1]);
	}	
	cout << ans << '\n';
	return 0;
}
