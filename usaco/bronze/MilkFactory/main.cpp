#include <iostream>
#include <fstream>
using namespace std;

int N;
int A[100], B[100], X[100];

void final_dest(int target) {
    for (int j = 0; j < N-1; j++) {
        if (A[j] == target) {
            X[B[j]-1]++;
            final_dest(B[j]);
        }
    }
}

int main() {
    ifstream fin ("factory.in");
    ofstream fout ("factory.out");

    fin >> N;
    for (int i = 0; i < N-1; i++) {
        fin >> A[i] >> B[i];
    }

    for (int i = 1; i <= N; i++) {
        final_dest(i);
    }

    for (int i = 0; i < N; i++) {
        if (X[i] == N-1) {
            fout << i+1 << "\n";
            return 0;
        }
    }
    fout << -1 << "\n";
    return 0;
}