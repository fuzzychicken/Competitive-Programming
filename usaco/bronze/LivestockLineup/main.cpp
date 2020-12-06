#include <bits/stdc++.h>

using namespace std;

int N;
string A[7], B[7];
string cows[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int idx(string c) {
    for (int i = 0; i < 8; i++)
        if (cows[i] == c) return i;
    return -1;
}

bool works() {
    for (int i = 0; i < N; i++) {
        int aidx = idx(A[i]);
        int bidx = idx(B[i]);
        if (abs(aidx - bidx) != 1) return false;
    }
    return true;
}

int main() {
    ifstream fin ("lineup.in");
    ofstream fout ("lineup.out");
    fin >> N;
    for (int i = 0; i < N; i++) {
        string t;
        fin >> A[i] >> t >> t >> t >> t >> B[i]; 
    }
    do {
        if (works()) {
            for (int i = 0; i < 8; i++) {
                fout << cows[i] << "\n";
            }
            break;
        }
    } while (next_permutation(cows, cows + 8));
    return 0;
}