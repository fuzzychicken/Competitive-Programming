#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> loc;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("socdist2.in","r",stdin);
    freopen("socdist2.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        loc.push_back({a,b});
    }
    sort(loc.begin(), loc.end(), [&](pair<int, int> x, pair<int, int> y) {
        return x.first < y.first;
    });
    int max_r = INT_MAX;
    for (int i = 1; i < n-1; i++) {
        if (loc[i].second == 0 && loc[i-1].second == 1) {
            max_r = min(max_r, loc[i].first-loc[i-1].first);
        }
        if (loc[i].second == 0 && loc[i+1].second == 1) {
            max_r = min(max_r, loc[i+1].first-loc[i].first);
        }
    }
    sort(loc.begin(), loc.end(), [&](pair<int, int> x, pair<int, int> y) {
        if (x.second == y.second) {
            return x.first < y.first;
        }
        return x.second > y.second;
    });
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (loc[i].second == 0) break;
        if (loc[i].first-loc[i-1].first >= max_r) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}