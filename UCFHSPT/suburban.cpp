#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int c;
    cin >> c;
    while (c--) {
        ll ans = 1e18;
        ll x;
        cin >> x;
        for (ll i = 0; i <= ceil(sqrt(x)); i++) {
            ll pp, pp2;
            ll q = x-(i*i);
            if (q < 0) q = 0;
            pp = ceil(sqrt(q));
            pp2 = floor(sqrt(q));
            // for (ll j = 0; j <= (pp); j++) {
            //     if (i*i + j*j == x) {
            //         ans = min(ans, i+j);
            //     }
            // }
            if (i*i + pp*pp == x) {
                ans = min(ans, pp+i);
            }
            if (i*i + pp2*pp2 == x) {
                ans = min(ans, pp2+i);
            }
        }
        if (ans == 1e18) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}