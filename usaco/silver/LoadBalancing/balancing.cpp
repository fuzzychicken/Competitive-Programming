#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef LOCAL
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);
    #endif

    int N;
    cin >> N;

    vector<pair<int, int>> coord(N);

    for (int i = 0; i < N; i++) {
        cin >> coord[i].first >> coord[i].second;
    }

    sort(coord.begin(), coord.end());

    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        int y = coord[i].second;
        int x = coord[0].first;
        int upRight = 0, upLeft = 0, downLeft = 0, downRight = 0;
        for (int j = 0; j < N; j++) {
            if (coord[j].second > y) {
                if (coord[j].first > x) {
                    upRight++;
                } else {
                    upLeft++;
                }
            } else {
                if (coord[j].first > x) {
                    downRight++;
                } else {
                    downLeft++;
                }
            }
        }
        ans = min(ans, max({upLeft, upRight, downLeft, downRight}));
        for (int j = 1; j < N - 1; j++) {
            if (coord[j].second > y) {
                upRight--;
                upLeft++;
            } else {
                downRight--;
                downLeft++;
            }
            ans = min(ans, max({upLeft, upRight, downLeft, downRight}));
        }
    }
    cout << ans << '\n';
}