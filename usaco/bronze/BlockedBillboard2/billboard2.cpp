#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int grid[2000][2000];

int main() {
    ifstream fin ("billboard.in");
    ofstream fout ("billboard.out");
    int x1, y1, x2, y2, cx1, cy1, cx2, cy2;
    fin >> x1 >> y1 >> x2 >> y2;
    fin >> cx1 >> cy1 >> cx2 >> cy2;
    x1 += 1000, y1 += 1000, x2 += 1000, y2 += 1000;
    cx1 += 1000, cy1 += 1000, cx2 += 1000, cy2 += 1000;
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            grid[j][i] = 1;
        }
    }
    for (int i = cx1; i < cx2; i++) {
        for (int j = cy1; j < cy2; j++) {
            if (grid[j][i] == 1) {
                grid[j][i] = 3;
            }
            else {
                grid[j][i] = 2;
            }
        }
    }
    // i kinda mixed up the naming... so just disregard names
    int maxx = 0, minx = 1000000, maxy = 0, miny = 1000000;
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            if (grid[j][i] == 1) {
                maxx = max(j, maxx);
                minx = min(j, minx);
                maxy = max(i, maxy);
                miny = min(i, miny);
            }
        }   
    }
    minx--, miny--;
    if (maxx == 0 && minx == 1e6-1 && maxy == 0 && miny == 1e6-1) {
        fout << 0 << endl;
        return 0;
    }
    fout << (abs(maxy-miny) * abs(maxx-minx)) << endl;
    return 0;
}