#include <bits/stdc++.h>
using namespace std;

int n, n1=0, n2=0;
vector<pair<int, int>> easts;
vector<pair<int, int>> norths;

int farthestgo3(pair<int, int> b);

int farthestgo(pair<int, int> b) {
    if (n1 == n) return 0;
    int x = b.first, y = b.second;
    bool ok = true;
    int fg = 0;
    for (auto a : easts) {
        if (a.first > x || a.second < y) continue;
        int ydist = a.second - y;
        int xdist = x - a.first;
        // if (farthestgo3(a) <= xdist) continue; 
        if (xdist < ydist) {
             fg = ydist;
             ok = false;
        }
        if (!ok) break;
    }
    return fg;
}

int farthestgo3(pair<int, int> b) {
    int x = b.first, y = b.second;
    bool ok = true;
    int fg = 0;
    for (auto a : norths) {
        if (a.first < x || a.second > y) continue;
        int ydist = y - a.second;
        int xdist = a.first - x;
        // if (farthestgo(a) <= ydist) {
        //     continue;
        // }
        if (ydist < xdist) {
             fg = xdist;
             ok = false;
        }
        if (!ok) break;
    }
    return fg;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<pair<int, int>> coord(n);
    vector<char> dir(n);
    
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> coord[i].first >> coord[i].second;
        if (dir[i] == 'E') {
            easts.push_back({coord[i].first,coord[i].second});
        } else {
            norths.push_back({coord[i].first,coord[i].second});
        }
    }
    sort(easts.begin(), easts.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    sort(norths.begin(), norths.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    // for (int i = 0; i < easts.size(); i++) {
    //     cerr << "EAST: " << easts[i].first << ' ' << easts[i].second << endl;
    // }
    // for (int i = 0; i < norths.size(); i++) {
    //     cerr << "NORTH: " << norths[i].first << ' ' << norths[i].second << endl;
    // }
    vector<int> ans(n, -10);
    for (int i = 0; i < n; i++) {
        int x = coord[i].first, y = coord[i].second;
        if (dir[i] == 'E') {
            bool ok = true;
            for (auto a : norths) {
                if (a.first < x || a.second > y) continue;
                int ydist = y - a.second;
                int xdist = a.first - x;
                if (farthestgo(a) <= ydist) {
                    continue;
                }
                if (ydist < xdist) {
                     ans[i] = xdist;
                     ok = false;
                }
                if (!ok) break;
            }
        } else {
            bool ok = true;
            for (auto a : easts) {

                if (a.first > x || a.second < y) continue;
                int ydist = a.second - y;
                int xdist = x - a.first;
                if (farthestgo3(a) <= xdist) continue; 
                if (xdist < ydist) {
                     ans[i] = ydist;
                     ok = false;
                }
                if (!ok) break;
            }
        }
    }
    for (int i : ans) {
        if (i == -10) cout << "Infinity\n";
        else {
            cout << i << '\n';
        }
    }
}