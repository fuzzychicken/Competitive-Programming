#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] != 0) {
        cout << 0 << '\n';
        return;
    }
    int cnt = 0, mexa = 0;
    vector<int> final;
    for (int i = 0; i < n; i++) {
        if (a[i] != cnt) 
            final.push_back(a[i]);
        else {
            mexa = a[i] + 1;
            cnt++;
        }
    }
    // for (int i : final) cout << i << '\n';
    if (final.empty() || final[0] != 0) {
        cout << mexa << '\n';
        return;
    }
    int cnt2 = 0, mexb;
    for (int i = 0; i < final.size(); i++) {
        if (final[i] == cnt2) {
            mexb = final[i] + 1;
            cnt2++;
        }
    }
    cout << mexb + mexa << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}