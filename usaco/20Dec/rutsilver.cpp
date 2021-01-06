#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<pair<int, int>> intersected[1000];
vector<pair<int, int>> easts;
vector<pair<int, int>> norths;
map<pair<int, int>, int> order;
vector<pair<int64_t, int64_t>> stops[1000];

void recurse(pair<int,int> pair) {
    for (auto pair2 : stops[order[pair]]) {
        cnt++;
        recurse(pair2);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    vector<pair<int, int>> coord(n);
    vector<char> direction(n);

    for (int i = 0; i < n; i++) {
        cin >> direction[i] >> coord[i].first >> coord[i].second;
        if (direction[i] == 'E') {
            easts.push_back({coord[i].first, coord[i].second});
        } else {
            norths.push_back({coord[i].first, coord[i].second});
        }
        order[coord[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int x = coord[i].first, y = coord[i].second;
        if (direction[i] == 'E') {
            for (auto a : norths) {
                if (a.first < x || a.second > y) continue;
                int ydist = y - a.second;
                int xdist = a.first - x;
                if (ydist < xdist) {
                    intersected[order[coord[i]]].push_back(a);
                }
            }
        } else {
            for (auto a : easts) {
                if (a.first > x || a.second < y) continue;
                int ydist = a.second - y;
                int xdist = x - a.first;
                if (xdist < ydist) {
                    intersected[order[coord[i]]].push_back(a);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (direction[i] == 'E') {
            sort(intersected[i].begin(), intersected[i].end());
   
            for (auto z : intersected[i]) {
                int min_y = INT_MAX;
                for (auto x : intersected[order[z]]) {
                    min_y = min(x.second, min_y);
                }
                if (coord[i].second <= min_y) {
                    stops[order[z]].push_back(coord[i]);
                    break;
                }
            }
            
        } else {
            sort(intersected[i].begin(), intersected[i].end(), [](pair<int, int> a, pair<int,int> b) {
                return a.second < b.second;
            });
            
            for (auto z : intersected[i]) {
                int min_x = INT_MAX;
                for (auto x : intersected[order[z]]) {
                    min_x = min(x.first, min_x);
                }
                if (coord[i].first <= min_x) {
                    stops[order[z]].push_back(coord[i]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (auto pair : stops[i]) {
            cnt++;
            recurse(pair);
        }
        cout << cnt << '\n';
    }
}
