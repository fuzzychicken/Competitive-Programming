#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> hitby[50];
vector<pair<int, int>> easts;
vector<pair<int, int>> norths;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    vector<pair<int, int>> coord(n);
    vector<char> dir(n);
    map<pair<int, int>, int> order;

    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> coord[i].first >> coord[i].second;
        if (dir[i] == 'E') {
            easts.push_back({coord[i].first, coord[i].second});
        } else {
            norths.push_back({coord[i].first, coord[i].second});
        }
        order[coord[i]] = i;
    }
    // sort(easts.begin(), easts.end(), [](pair<int, int> a, pair<int, int> b) {
    //     if (a.second == b.second) {
    //         return a.first < b.first;
    //     }
    //     return a.second < b.second;
    // });
    // sort(norths.begin(), norths.end(), [](pair<int, int> a, pair<int, int> b) {
    //     if (a.first == b.first) {
    //         return a.second > b.second;
    //     }
    //     return a.first < b.first;
    // });

    assert(easts.size() + norths.size() == n);

    for (int i = 0; i < n; i++) {
        int x = coord[i].first, y = coord[i].second;
        if (dir[i] == 'E') {
            for (auto a : norths) {
                if (a.first < x || a.second > y) continue;
                int ydist = y - a.second;
                int xdist = a.first - x;
                if (ydist < xdist) {
                    hitby[order[coord[i]]].push_back(a);
                }
            }
        } else {
            for (auto a : easts) {

                if (a.first > x || a.second < y) continue;
                int ydist = a.second - y;
                int xdist = x - a.first;
                if (xdist < ydist) {
                    hitby[order[coord[i]]].push_back(a);
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << hitby[i] << '\n';
    // }

    for (int i = 0; i < n; i++) {
        if (dir[i] == 'E') {
            sort(hitby[i].begin(), hitby[i].end());
            
            bool ok = true;
            for (auto z : hitby[i]) {
                int lowesty = INT_MAX;
                for (auto x : hitby[order[z]]) {
                    lowesty = min(x.second, lowesty);
                }
                if (coord[i].second <= lowesty) {
                    cout << abs(z.first - coord[i].first) << '\n';
                    ok = false;
                }
                if (!ok) break;
            }
            if (ok) cout << "Infinity\n";
            
        } else {
            sort(hitby[i].begin(), hitby[i].end(), [](pair<int, int> a, pair<int,int> b) {
                return a.second < b.second;
            });
            
            bool ok = true;
            for (auto z : hitby[i]) {
                int lowestx = INT_MAX;
                for (auto x : hitby[order[z]]) {
                    lowestx = min(x.first, lowestx);
                }
                if (coord[i].first <= lowestx) {
                    cout << abs(z.second - coord[i].second) << '\n';
                    ok = false;
                }
                if (!ok) break;
            }
            if (ok) cout << "Infinity\n";
        }
    }
}
