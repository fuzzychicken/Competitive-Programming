#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, p[100000];
vector<pair<int, pair<int, int>>> wormhole;

bool works(int w) {
    pair<int, pair<int, int>> a = {w, {0, 0}};
    int idx = lower_bound(wormhole.begin(), wormhole.end(), a) - wormhole.begin();
    vector<int> adj[100000];
    for (int i = idx; i < m; i++) {
        adj[wormhole[i].second.first].push_back(wormhole[i].second.second);
        adj[wormhole[i].second.second].push_back(wormhole[i].second.first);
    }
    int visited[100000];
    for (int i = 0; i < n; i++) {
        visited[i] = -1;
    }
    int comp = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) { 
        if (visited[i] < 0) {
            q.push(i);
            visited[i] = comp;
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                for (int e : adj[x]) {
                    if (visited[e] < 0) {
                        q.push(e);
                    }
                    visited[e] = comp;
                }
            }
            comp++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] != visited[p[i]]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin ("wormsort.in");
    ofstream fout ("wormsort.out");
    fin >> n >> m;
    for (int i = 0; i < n; i++) {
        fin >> p[i];
        p[i]--;
    }
    wormhole.resize(m);
    int maxw = 0;
    for (int i = 0; i < m; i++) {
        fin >> wormhole[i].second.first >> wormhole[i].second.second >> wormhole[i].first;
        wormhole[i].second.first--, wormhole[i].second.second--;
        maxw = max(maxw, wormhole[i].first);
    }
    sort(wormhole.begin(), wormhole.end());
    int lo = 0, hi = maxw + 2;
    while (lo < hi - 1) { 
        int mid = (lo + hi) / 2; 
        if (works(mid)) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    } 
    if (lo > maxw) {
        fout << -1 << '\n';
        return 0;
    }
    fout << lo << '\n';
    return 0;
}
