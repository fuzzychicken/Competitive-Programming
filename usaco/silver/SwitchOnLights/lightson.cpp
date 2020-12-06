#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int N, M, numIlluminated;
bool visited[MAXN][MAXN], alreadyOn[MAXN][MAXN];
vector<pair<int, int>> adj[MAXN][MAXN];

bool withinBounds(int x, int y) {
    if (x >= N || x < 0) {
        return false;
    }
    if (y >= N || y < 0) {
        return false;
    }
    return true;
}

void search(pair<int, int> start) {
    int x = start.first;
    int y = start.second;
    visited[x][y] = true;

    for (pair<int, int> n : adj[x][y]) {
        int nx = n.first;
        int ny = n.second;

        // Illuminate all possible lights using switches from this room
        if (!alreadyOn[nx][ny]) {
            numIlluminated++; 

            alreadyOn[nx][ny] = true;

            // If it is possible to visit this cell, visit it
            if (withinBounds(nx-1, ny) && visited[nx-1][ny] && alreadyOn[nx-1][ny]) {
                search({nx, ny});
            }
            if (withinBounds(nx+1, ny) && visited[nx+1][ny] && alreadyOn[nx+1][ny]) {
                search({nx, ny});
            }
            if (withinBounds(nx, ny-1) && visited[nx][ny-1] && alreadyOn[nx][ny-1]) {
                search({nx, ny});
            }
            if (withinBounds(nx, ny+1) && visited[nx][ny+1] && alreadyOn[nx][ny+1]) {
                search({nx, ny});
            }
        }
    }

    // See if Bessie can go to any neighbors of the current cell
    if (withinBounds(x-1, y) && !visited[x-1][y] && alreadyOn[x-1][y]) {
        search({x-1, y});
    }
    if (withinBounds(x+1, y) && !visited[x+1][y] && alreadyOn[x+1][y]) {
        search({x+1, y});
    }
    if (withinBounds(x, y-1) && !visited[x][y-1] && alreadyOn[x][y-1]) {
        search({x, y-1});
    }
    if (withinBounds(x, y+1) && !visited[x][y+1] && alreadyOn[x][y+1]) {
        search({x, y+1});
    }
}

int main() {
    ifstream fin ("lightson.in");
    ofstream fout ("lightson.out");
    fin >> N >> M;

    for (int i = 0; i < M; i++) {   
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        x--, y--, a--, b--;
        adj[x][y].push_back({a, b});
    }

    alreadyOn[0][0] = true;

    search({0, 0});

    fout << numIlluminated + 1 << '\n';
    return 0;
}
