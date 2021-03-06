#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[50000];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int p1 = 0, p2 = 0;
    vector<pair<int, int>> bounds;
    while (p2 < n-1) {
        if (a[p2+1] - a[p1] <= k) {
            p2++;
        }
        else {
            bounds.push_back({p1, p2});
            p1++;
        }  
    }
    bounds.push_back({p1, p2});
    int ans = 0;
    for (int i = 0; i < bounds.size(); i++) {
        for (int j = i+1; j < bounds.size(); j++) {
            int combined = 0;
            if (bounds[i].second >= bounds[j].first - 1) {
                combined = bounds[j].second - bounds[i].first + 1;
            }
            else {
                combined = bounds[i].second - bounds[i].first + bounds[j].second - bounds[j].first + 2;
            }
            ans = max(ans, combined);
        }
    }
    cout << ans << '\n';
    return 0;
}