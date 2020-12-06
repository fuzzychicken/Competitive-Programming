#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> loc;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        loc.push_back(a);
    }
    sort(loc.begin(), loc.end());
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        int aa = lower_bound(loc.begin(), loc.end(), a) - loc.begin();
        int bb = upper_bound(loc.begin(), loc.end(), b) - loc.begin();
        cout << bb-aa << '\n';
    }
    return 0;
}