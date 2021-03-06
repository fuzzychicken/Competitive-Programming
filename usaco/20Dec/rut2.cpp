#include <bits/stdc++.h>
using namespace std;

int n, n1=0, n2=0;
vector<pair<int, int>> easts;
vector<pair<int, int>> norths;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<pair<int, int>> coord(n);
    vector<char> dir(n);
    map<pair<int,int>, int> locfg;
    vector<pair<int, pair<int, int>>> print(n);
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> coord[i].first >> coord[i].second;
        if (dir[i] == 'E') {
            easts.push_back({coord[i].first,coord[i].second});
        } else {
            norths.push_back({coord[i].first,coord[i].second});
        }
        locfg[coord[i]] = -1;
        print[i] = {i, coord[i]};
    }
    sort(easts.begin(), easts.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    sort(norths.begin(), norths.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    assert(easts.size() + norths.size() == n);

   // for (int i = 0; i < easts.size(); i++) {
   //      cerr << "EAST: " << easts[i].first << ' ' << easts[i].second << endl;
   //  }
   //  for (int i = 0; i < norths.size(); i++) {
   //      cerr << "NORTH: " << norths[i].first << ' ' << norths[i].second << endl;
   //  }

    for (int i = 0; i < easts.size(); i++) {
        int x = easts[i].first, y = easts[i].second;
        bool ok = true;
        for (auto a : norths) {
            if (a.first < x || a.second > y) continue;
            int xdist = a.first - x;
            int ydist = y - a.second;
            if (ydist < xdist) {
                locfg[easts[i]] = xdist;
                ok = false;
            } else if (xdist < ydist) {
                locfg[a] = ydist;
                auto it = find(norths.begin(), norths.end(), a);
                norths.erase(it);
            }
            if (!ok) break;
        }
    }
    // for (int i = 0; i < norths.size(); i++) {
    //     int x = norths[i].first, y = norths[i].second;
    //     bool ok = true;
    //     for (auto a : easts) {

    //         if (a.first > x || a.second < y) continue;
    //         int xdist = x - a.first;
    //         int ydist = a.second - y;
            
    //         if (ydist < xdist) {
    //             locfg[a] = xdist;
    //         } else if (xdist < ydist) {
    //             locfg[norths[i]] = ydist;
    //             ok = false;
    //         }
    //         if (!ok) break;
    //     }
    // }
    for (auto x : print) {
        if (locfg[x.second] == -1) cout << "Infinity\n";
        else cout << locfg[x.second] << '\n';
    }
}