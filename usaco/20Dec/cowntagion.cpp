#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> adj[100000];
bool vis[100000], vis2[100000];

void dfs(int node) {
    vis[node] = true;
    int x = 0;

    for (int i : adj[node]) {
        if (!vis2[i]) {
            ++x;
            vis2[i] = true;
        }
    }

    ans += (int) ceil(log(x+1)/log(2)) + x;
    // ans ++ (int) ceil(log2(x+1)) + x:

    for (int i : adj[node]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis2[0] = true;
    dfs(0);
    cout << ans << '\n';
}