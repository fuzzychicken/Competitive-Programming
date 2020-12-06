#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int c;
    cin >> c;
    while (c--) {
        long long n, k;
        cin >> n >> k;
        long long soldiers[n];
        int diff[n+1];
        diff[0] = 0;
        long long tot = 0;
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
            long long b;
            cin >> b;
            if (diff[b] > 0) tot += diff[b];
        }
        cout << tot << '\n';
    }
}
