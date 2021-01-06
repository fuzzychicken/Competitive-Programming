#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 1002;

int n, k;
int grid[MAXN][MAXN];

int main() {
    ifstream fin ("paintbarn.in");
    ofstream fout ("paintbarn.out");
    fin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            grid[x][y1]++;
            grid[x][y2]--;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (grid[i][j] == k) {
                cnt++;
            }
            grid[i][j+1] += grid[i][j];
        }
    }
    fout << cnt << '\n';
}
