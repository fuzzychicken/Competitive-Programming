#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int c;
    cin >> c;
    while (c--) {
        int t;
        ll ans = 1;
        cin >> t;
        for (int i = 0; i < t; i++) {
            ll cnt = 0;
            for (int j = 0; j <= 9; j++) {
                if (j % 3 == 0) cnt++;
            }
            ans *= cnt;
        }
        cout << ans << '\n';
    }
}
