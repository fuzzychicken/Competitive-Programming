#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, start, cnt;
bool visited[3000], past[3000];
vector<int> adj[3000];

void dfs(int node) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

int main() {
    ifstream fin ("closing.in");
    ofstream fout ("closing.out");
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cnt = 0;
    dfs(0);
    if (cnt == n-1) {
        fout << "YES" << endl;
    }
    else {
        fout << "NO" << endl;
    }
    for (int i = 1; i < n; i++) {
        int curr;
        fin >> curr;
        curr--;
        memset(visited, false, sizeof(visited));
        past[curr] = true;
        for (int j = 0; j < n; j++) {
            if (past[j] == true) {
                visited[j] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (j != curr && visited[j] == false) {
                start = j;
                break;
            }
        }
        cnt = 0;
        dfs(start);
        if (cnt == n-i-1) {
            fout << "YES" << endl;
        }
        else {
            fout << "NO" << endl;
        }
    }
    return 0;
}