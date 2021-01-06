#include <bits/stdc++.h>
using namespace std;
 
int n, k;
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0 && v[i+1] != v[i] && v[i] == mx) ans = i+1;
        else if (i == n-1 && v[i-1] != v[i] && v[i] == mx) ans = i+1;
        else if (i != n-1 && i != 0) {
            if ((v[i] != v[i-1] || v[i] != v[i+1]) && v[i] == mx) ans = i+1;
        }
    }
    cout << ans << '\n';
    vector<int> hello(n);
    for (auto &i : hello) {
        cin >> i;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
