#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int sum = 0;
	
	for (int i = n-1; i >= 2; i--) {
		sum += (n-i);
	}
	sum += 2;
	for (int i = 0; i < n; i++) {
		
	}
	cout << sum << '\n';
	return 0;
}
