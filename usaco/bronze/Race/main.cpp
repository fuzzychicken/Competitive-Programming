#include <iostream>
#include <fstream>
using namespace std;

int K, N, X;

int main() {
    ifstream fin ("race.in");
    ofstream fout ("race.out");
    fin >> K >> N;
    for (int i = 0; i < N; i++) {
        int X;
        fin >> X;
        int advanceDist = 0;
        int returnDist = 0;
        int currSpeed = 0;
        int cnt = 0;
        while (true) {
            currSpeed++;
            advanceDist += currSpeed;
            cnt++;
            if (advanceDist + returnDist >= K) break;
            if (currSpeed >= X) {
                returnDist += currSpeed;
                cnt++;
                if (returnDist + advanceDist >= K) break;
            }
        }
        fout << cnt << "\n";
    }
    return 0;
}