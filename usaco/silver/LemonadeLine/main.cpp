#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, line[100000];

int main() {
    ifstream fin ("lemonade.in");
    ofstream fout ("lemonade.out");
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> line[i];
    }
    sort(line, line + N);
    int cnt = 0;
    for (int i = N-1; i >= 0; i--) {
        if (cnt <= line[i]) {
            cnt++;
        }
        else {
            break;
        }
    }
    fout << cnt << "\n";
    return 0;
}
