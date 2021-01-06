#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> candy(n);
        int tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> candy[i]; 
            tot += candy[i];
        }
        bool ok = false;
        if (tot % 2 == 0 && (tot/2) % 2 == 0) ok = true; 
        cout << (ok ? "YES\n" : "NO\n");
    }
}
