#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> n(7);
    int mx = 0;
    for (int i = 0; i < 7; i++) {
        cin >> n[i];
        mx = max(mx, n[i]);
    }
    sort(n.begin(), n.end());
    for (int i = 0; i < 7; i++) {
        for (int j = i+1; j < 7; j++) {
            for (int k = j+1; k < 7; k++) {
                if (n[i] + n[j] + n[k] == mx) {
                    cout << n[i] << ' ' << n[j] << ' ' << n[k] << '\n';
                    exit(0);
                }
            }
        }
    }
}