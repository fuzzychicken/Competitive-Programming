#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2001;

int n;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];   
string s;

bool withinBounds(int x, int y) {
    if (x > MAXN - 1 || x < 0 || y > MAXN - 1 || y < 0) {
        return false;
    }
    return true;
}

int main() {
    ifstream fin ("gates.in");
    ofstream fout ("gates.out");
    fin >> n >> s;

    int startx = 1000, starty = 1000;

    grid[startx][starty] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            grid[startx-2][starty] = 1;
            grid[startx-1][starty] = 1;
            startx -= 2;
        } else if (s[i] == 'S') {
            grid[startx+2][starty] = 1;
            grid[startx+1][starty] = 1;
            startx += 2;
        } else if (s[i] == 'E') {
            grid[startx][starty+2] = 1;
            grid[startx][starty+1] = 1;
            starty += 2;
        } else {
            grid[startx][starty-2] = 1;
            grid[startx][starty-1] = 1;
            starty -= 2;
        }
    }
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int comp = 0;

    queue<pair<int, int>> q;

    // find number of components
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {

            if (!visited[i][j] && grid[i][j] == 0) {

                q.push({i, j});
                visited[i][j] = true;

                while(!q.empty()) {
                    pair<int, int> v = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int x = v.first + dx[i];
                        int y = v.second + dy[i];

                        if (withinBounds(x, y) && !visited[x][y] && grid[x][y] == 0) {
                            q.push({x, y});
                            visited[x][y] = true;
                        }
                    }
                }
                comp++;
            }
        }
    }

    // answer is number of components i - 1
    fout << comp - 1 << '\n';

    return 0;
}
