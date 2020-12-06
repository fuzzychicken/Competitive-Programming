#include <bits/stdc++.h>
using namespace std;

long long fact(long long n) {
	if (n == 0) 
        return 1; 
    return n * fact(n - 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long n;
	cin >> n; 
	cout << (fact(n) * fact(n)) / 6 << '\n';
	return 0;
}