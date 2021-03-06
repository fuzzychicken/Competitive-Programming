#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	int profit[n];
    for (int i = 0; i < n; i++) { cin >> a[i];
    }

	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		profit[i] = r-c;
	}
	
	int mx = 0, sum = 0;
    for (int i = 0; i < n; i++) { 
        sum += profit[i];
        if (sum < 0) {
        	sum = 0;
        }
        mx = max(mx, sum);
    }

    cout << mx << '\n';
	return 0;
}
