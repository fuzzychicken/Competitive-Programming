#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> p(n);
    for (int &i : p) cin >> i;
    sort(p.begin(), p.end());
    int ans = 0, p1 = 0, p2 = n-1;
    while (p1 <= p2) {
        if (p[p1] + p[p2] > x) {
            ans++;
            p2--;
        } else {
            ans++;
            p1++;
            p2--;
        }
    }
    cout << ans << '\n';
}
