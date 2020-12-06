#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int N;
int coord[100][2];

int main() {
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");
    fin >> N;
    for (int i = 0; i < N; i++) {
        int first, second;
        fin >> first >> second;
        coord[i][0] = first;
        coord[i][1] = second;
    }
    int best = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            for (int k = j+1; k < N; k++) {
                set<int> x;
                set<int> y;
                x.insert(coord[i][0]);
                x.insert(coord[j][0]);
                x.insert(coord[k][0]);
                y.insert(coord[i][1]);
                y.insert(coord[j][1]);
                y.insert(coord[k][1]);
                if (y.size() == 2 && x.size() == 2) {
                    int xmax = max(coord[i][0], max(coord[j][0], coord[k][0]));
                    int xmin = min(coord[i][0], min(coord[j][0], coord[k][0]));
                    int ymax = max(coord[i][1], max(coord[j][1], coord[k][1]));
                    int ymin = min(coord[i][1], min(coord[j][1], coord[k][1]));
                    best = max(best, abs((xmax-xmin) * (ymax-ymin)));
                }
            }
        }
    }
    fout << best << "\n";
    return 0;
}