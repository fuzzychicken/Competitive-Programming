#include <bits/stdc++.h>
using namespace std;

long long fact(long long n) {
	if (n == 0) 
        return 1; 
    return n * fact(n - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //xcode c++ code
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (k == j == i) {
                    cout << "pen\n";
                }
            }
        }
    }
}
