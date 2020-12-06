#include <bits/stdc++.h>

using namespace std;

int n, cnt;
vector<int> adj[200];
int x[200], y[200], p[200];
bool can_reach[200][200], visited[200];

void dfs(int node) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            cnt++; dfs(next);
        }
    }
}

int main() {
    ifstream fin ("moocast.in");
    ofstream fout ("moocast.out");
    fin >> n;

    // read in input
    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i] >> p[i];
    }

    // find out which points can reach each other
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dist <= p[i] * p[i]) {
                can_reach[i][j] = true;
            }
        }
    }

    // read in graph based on prev. info
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (can_reach[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

    // run dfs and find largest amt of nodes that can be reached
    int ans = 1;
    for (int i = 0; i < n; i++) {
        cnt = 1;
        memset(visited, false, sizeof(visited));
        dfs(i);
        ans = max(ans, cnt);
    }
    fout << ans << '\n';
    return 0;
}
