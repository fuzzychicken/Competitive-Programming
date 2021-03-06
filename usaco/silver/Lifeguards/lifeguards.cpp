#include <bits/stdc++.h>
using namespace std;

struct PT {
	int l, r;
};

int n, lb, curmax, total, res = INT_MAX;
vector<PT> shifts;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("lifeguards.in","r",stdin);
	freopen("lifeguards.out","w",stdout);
	cin >> n;
	shifts.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> shifts[i].l >> shifts[i].r;
	}
	sort(shifts.begin(), shifts.end(), [](PT a, PT b) {
		return a.l < b.l;
	});
	for (int i = 0; i < n; i++) {
		if (shifts[i].r > lb) {s
			curmax = max(lb, shifts[i].l);
			total += shifts[i].r - curmax;
			lb = shifts[i].r;
		}
	}
	lb = 0;
	for (int i = 0; i < n-1; i++) {
		if (shifts[i].r <= lb) {
			res = 0;
		} else {
			int a = min(shifts[i].r, shifts[i+1].l);
			int b = max(shifts[i].l, lb);
			res = min(a-b, res);
			lb = max(shifts[i].r, lb);
		}
	}
	if (res < 0) res = 0;
	cout << total - res << '\n';
	return 0;
}
