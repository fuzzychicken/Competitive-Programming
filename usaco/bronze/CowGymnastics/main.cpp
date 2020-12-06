#include <iostream>
#include <fstream>
using namespace std;

int K, N;
int order[10][20];

int main() {
    ifstream fin ("gymnastics.in");
    ofstream fout ("gymnastics.out");
    fin >> K >> N;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            fin >> order[i][j];
        }
    }
    int first = 0;
    int second = 0;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            bool ok = true;
            for (int k = 0; k < K; k++) {
                for (int u = 0; u < N; u++) {
                    if (i == order[k][u]) first = u;
                    if (j == order[k][u]) second = u;
                }
                if (first < second) {
                    ok = false;
                    break;
                }
            }
            if (ok) cnt++;
        }
    }
    fout << cnt << "\n";
    return 0;
}