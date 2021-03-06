#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second; 
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    int prev = 0, cnt = 0;
    for (pair<int, int> x : a) {
        if (x.first >= prev) cnt++, prev = x.second;
    }
    cout << cnt << '\n';
}
