#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int k, m, n;
	cin >> k >> m >>n;
	if (n >= k * 10) cout << 0 << '\n';
	else {
		double need = 10.0 * k - n;
		cout << ceil(need/m) << '\n';
	}
	return 0;
}
