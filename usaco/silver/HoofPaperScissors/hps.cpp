#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+1;

int n;
int winner[MAXN][3]; // H = 0, P = 1, S = 2

int main() {
    ifstream fin ("hps.in");
    ofstream fout ("hps.out");

    fin >> n;

    for (int i = 1; i <= n; i++) {
        char curr;
        fin >> curr;
        if (curr == 'H') {
            winner[i][0] = ++winner[i-1][0];
            winner[i][1] = winner[i-1][1];
            winner[i][2] = winner[i-1][2];
        }
        else if (curr == 'P') {
            winner[i][0] = winner[i-1][0];
            winner[i][1] = ++winner[i-1][1];
            winner[i][2] = winner[i-1][2];
        }
        else {
            winner[i][0] = winner[i-1][0];
            winner[i][1] = winner[i-1][1];
            winner[i][2] = ++winner[i-1][2];
        }
    }
    
    int best = 0;
    for (int i = 1; i <= n-1; i++) {
        int first = max(winner[i][0], max(winner[i][1], winner[i][2]));
        int second = max(winner[n][0] - winner[i][0], max(winner[n][1] - winner[i][1], winner[n][2] - winner[i][2]));
        best = max(best, first + second);
    }   

    fout << best << '\n';
    return 0;
}
