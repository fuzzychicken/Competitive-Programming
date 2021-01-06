#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> adj[100000];

void dfs(int u, int p) {
    int x = p == -1 ? adj[u].size() : adj[u].size() - 1;
    ans += ceil(log2(x+1)) + x;
    for (int i : adj[u]) {
        if (i != p) {
            dfs(i, u);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << ans << '\n';
}
// this solution involves dfs on a tree
// store parent and don't go back to it :)
// use log stuff to find how many days to duplicate
// keep running count of total days
