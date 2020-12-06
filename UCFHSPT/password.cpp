#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int c;
    cin >> c;
    while (c--) {
        int t;
        long long ans = 1;
        cin >> t;
        for (int i = 0; i < t; i++) {
            long long cnt = 0;
            for (int j = 0; j <= 9; j++) {
                if (j % 3 == 0) cnt++;
            }
            ans *= cnt;
        }
        cout << ans << '\n';
    }
}