#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int N;
string A, B;

int main() {
    ifstream fin ("breedflip.in");
    ofstream fout ("breedflip.out");
    fin >> N;
    fin >> A;
    fin >> B;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            if (A[i+1] == B[i+1]) 
                cnt++;
        }
    }
    fout << cnt << "\n";
    return 0;
} 