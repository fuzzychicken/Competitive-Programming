#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int n, m, comp = 0;
vector<int> adj[MAXN];
char s[MAXN];
int visited[MAXN];

void dfs(int node) {
    visited[node] = comp;
    for (int e : adj[node]) {
        if (visited[e] < 0 && s[e] == s[node]) {
            dfs(e);
        }
    }
}

int main() {
    ifstream fin ("milkvisits.in");
    ofstream fout ("milkvisits.out");
    fin >> n >> m;
    fin >> s;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        fin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visited, -1, sizeof(visited));

    /* -------- BELOW IS BFS IMPLEMENTATION -------- */

    // queue<int> q;
    // int group = 0;
    // for (int i = 0; i < n; i++) {
    //     if (visited[i] == -1) {
    //         q.push(i);
    //         char curr = s[i];
    //         while (!q.empty()) {
    //             int x = q.front();
    //             q.pop();
    //             visited[x] = group;
    //             for (int e : adj[x]) {
    //                 if (visited[e] == -1 && s[e] == curr) {
    //                     q.push(e);
    //                 }
    //             }
    //         }
    //         group++;
    //     }
    // }

    /* --------------------------------------------- */

    for (int i = 0; i < n; i++) {
        if (visited[i] < 0) {
            dfs(i);
            comp++;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char type;
        fin >> a >> b;
        fin >> type;
        a--, b--;
        if (s[a] != s[b]) {
            fout << 1;
        }
        else {
            if (s[a] == type || visited[a] != visited[b]) {
                fout << 1;
            }
            else {
                fout << 0;
            }
        }
    }
    fout << endl;
    return 0;
}