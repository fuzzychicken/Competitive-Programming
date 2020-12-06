#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Edge {
    int to, weight;
    Edge(int dest, int w):
    to(dest), weight(w)
    {}
};

int n, q;
vector<Edge> adj[5000]; 
int dist[5000];

int bfs(int start, int k) {
    int cnt = 0;
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    int c = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        c++;
        for (Edge e : adj[v]) {
            if (dist[e.to] == -1) {
                if (c > 1) {
                    dist[e.to] = min(dist[v], e.weight);
                }
                else {
                    dist[e.to] = e.weight;
                }
                q.push(e.to);
            }
        }
    }
    for (int i = 0; i < 5000; i++) {
        if (dist[i] >= k) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ifstream fin ("mootube.in");
    ofstream fout ("mootube.out");
    fin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int pi, qi, ri;
        fin >> pi >> qi >> ri;
        pi--, qi--;
        adj[pi].push_back(Edge(qi, ri));
        adj[qi].push_back(Edge(pi, ri));
    }
    for (int i = 0; i < q; i++) {
        int k, start;
        fin >> k >> start;
        start--;
        fout << bfs(start, k) << endl;
    }
    return 0;
}
