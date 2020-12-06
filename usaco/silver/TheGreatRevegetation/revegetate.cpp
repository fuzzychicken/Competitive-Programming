#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    bool same;
    Edge(int a, bool b):
    to(a), same(b)
    {}
};

const int MAXN = 1e5;

int n, m;
int visited[MAXN];
vector<Edge> adj[MAXN];
bool impossible;

/* COMMENTED CODE IS THE DFS IMPLEMENTATION OF THIS PROBLEM */

// void dfs(int node, int color) {
//      visited[node] = color;
//      for (Edge e : adj[node]) {
//         if (e.same) {
//             if (visited[e.to] == 3-color) {
//                 impossible = true;
//             }
//             else if (visited[e.to] < 0) {
//                 dfs(e.to, color);
//             }
//         }
//         else {
//             if (visited[e.to] == color) {
//                 impossible = true;
//             }
//             else if (visited[e.to] < 0) {
//                 dfs(e.to, 3-color);
//             }
//         }
//     }
// }

int main() {
    ifstream fin ("revegetate.in");
    ofstream fout ("revegetate.out");
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        char c;
        int a, b;
        fin >> c >> a >> b;
        a--, b--;
        if (c == 'S') {
            adj[a].push_back(Edge(b, true));
            adj[b].push_back(Edge(a, true));
        }
        else {
            adj[a].push_back(Edge(b, false));
            adj[b].push_back(Edge(a, false));
        }
    }
    memset(visited, -1, sizeof(visited));
    int num_components = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        // if (visited[i] < 0) {
        //     dfs(i, 1);
        //     num_components++;
        // }
        if (visited[i] < 0) {
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (Edge e : adj[x]) {
                    if (e.same) {
                        if (visited[e.to] == 3 - visited[x]) {
                            impossible = true;
                            break;
                        }
                        else {
                            if (visited[e.to] < 0) {
                                visited[e.to] = visited[x];
                                q.push(e.to);
                            }
                        }
                    }
                    else {
                        if (visited[e.to] == visited[x]) {
                            impossible = true;
                            break;
                        }
                        else {
                            if (visited[e.to] < 0) {
                                visited[e.to] = 3 - visited[x];
                                q.push(e.to);
                            }
                        }
                    }
                }
            }
            num_components++;
        }
    }
    if (impossible) {
        fout << 0 << endl;
        return 0;
    }
    fout << 1;
    for (int i = 0; i < num_components; i++) {
        fout << 0;
    }
    return 0;
} 