#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2002;

int grid[MAXN][MAXN];
int fx1, fy1, fx2, fy2;
int sx1, sy1, sx2, sy2;
int tx1, ty1, tx2, ty2;

int main() {
    ifstream fin ("billboard.in");
    ofstream fout ("billboard.out");
    fin >> fx1 >> fy1 >> fx2 >> fy2;
    fin >> sx1 >> sy1 >> sx2 >> sy2;
    fin >> tx1 >> ty1 >> tx2 >> ty2;
    fx1 += 1000, fy1 += 1000, fx2 += 1000, fy2 += 1000;
    sx1 += 1000, sy1 += 1000, sx2 += 1000, sy2 += 1000;
    tx1 += 1000, ty1 += 1000, tx2 += 1000, ty2 += 1000;
    for (int i = fx1; i < fx2; i++) {
        for (int j = fy1; j < fy2; j++) {
            grid[i][j] = 1;
        }
    }
    for (int i = sx1; i < sx2; i++) {
        for (int j = sy1; j < sy2; j++) {
            grid[i][j] = 1;
        }
    }
    for (int i = tx1; i < tx2; i++) {
        for (int j = ty1; j < ty2; j++) {
            grid[i][j] = 3;
        }
    }
    int cnt = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (grid[i][j] == 1) {
                cnt++;
            }
        }
    }
    fout << cnt << "\n";
    return 0;
}