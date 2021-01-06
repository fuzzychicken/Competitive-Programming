#include <bits/stdc++.h>
using namespace std;

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << to_string(h); if (sizeof...(t)) cerr << ", ";DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
    #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
 
const int MAXN = 101;

int x, y, k, m, ans = INT_MAX;
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
queue<pair<int, int>> q;

void go(int a, int b, int prev1) {
    if (!vis[a][b] && (prev1 + 1) <= k) {
        vis[a][b] = true;
        dist[a][b] = prev1 + 1;
        ans = min(ans, abs(m - (a + b)));
        q.push({a, b});
    }
}

int main() {
    ifstream fin ("pails.in");
    ofstream fout ("pails.out");

    fin >> x >> y >> k >> m;

    q.push({0, 0});
    vis[0][0] = true; 

    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        int previous = dist[v.first][v.second];

        // option 1;
        go(x, v.second, previous);
        go(v.first, y, previous);
        
        // option 2;
        go(0, v.second, previous);
        go(v.first, 0, previous);

        // option 3
        // pour second to first
        if (x - v.first < v.second) {
            int temp = v.first + (x - v.first);
            int temp2 = v.second - (x - v.first);
            go(temp, temp2, previous);
        } else {
            int temp = v.first + v.second;
            int temp2 = 0;
            go(temp, temp2, previous);
        }

        // pour first to second
        if (y - v.second < v.first) {
            int temp = v.second + (y - v.second);
            int temp2 = v.first - (y - v.second);
            go(temp2, temp, previous);
        } else {
            int temp = v.second + v.first;
            int temp2 = 0;
            go(temp2, temp, previous);
        }
    }

    fout << ans << '\n';
    return 0;
}
