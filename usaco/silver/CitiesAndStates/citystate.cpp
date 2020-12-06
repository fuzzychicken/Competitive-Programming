#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("citystate.in","r",stdin);
    // freopen("citystate.out","w",stdout);
    cin >> n;
    multiset<string> s;
    set<string> g;
    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        string bb = "";
        bb += a[0];
        bb += a[1];
        string final = "";
        if (int (bb[0]) < (int)b[0]) {
            final += bb[0];
            final += bb[1];
            final += b;
        }
        else {
            final += b;
            final += bb[0];
            final += bb[1];
        }
        s.insert(final);
        g.insert(final);
    }
    int ans = 0;
    for (auto c : g) {
        // cout << c << '\n';
        if (s.count(c) >= 2) 
            ans += (s.count(c) / 2);
    }
    cout << ans << '\n';
    return 0;
}
