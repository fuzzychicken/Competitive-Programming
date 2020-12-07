#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int c;
    cin >> c;
    while (c--) {
        ll n, k;
        cin >> n >> k;
        ll soldiers[n];
        int diff[n+1];
        diff[0] = 0;
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> soldiers[i];
            int adder;
            if (soldiers[i] > 0) {
                adder = 1;
            } else if (soldiers[i] < 0) {
                adder = -1;
            }
            diff[i+1] = adder + diff[i];
            tot += soldiers[i];
        }
        for (int i = 0; i < k; i++) {
            ll b;
            cin >> b;
            if (diff[b] > 0) {
                tot += diff[b];
            } 
        }
        cout << tot << '\n';
    }
    return 0;
}
