#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int c;
    cin >> c;
    while (c--) {
        long long ans = 1e18;
        long long x;
        cin >> x;
        for (long long i = 0; i <= ceil(sqrt(x)); i++) {
            long long pp, pp2;
            long long q = x-(i*i);
            if (q < 0) q = 0;
            pp = ceil(sqrt(q));
            pp2 = floor(sqrt(q));
            // for (long long j = 0; j <= (pp); j++) {
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
        cout  << ans << '\n';
    }
}