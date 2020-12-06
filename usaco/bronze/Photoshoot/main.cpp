#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N, B[1002];
vector<int> A;

bool contain(int idx) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == idx) return true;
    }
    return false;
}

int main() {
    ifstream fin ("photo.in");
    ofstream fout ("photo.out");
    fin >> N;
    for (int i = 0; i < N-1; i++) {
        fin >> B[i];
    }
    int idx = -1;
    for (int i = 1; i <= N; i++) {
        A.clear();
        A.push_back(i);
        idx = i;
        for (int j = 0; j < N-1; j++) {
            int good = B[j] - idx;
            if (good > N || contain(good)) break;
            A.push_back(good);
            idx = good;
        }
        if (A.size() == N) break;
    }
    for (int i = 0; i < N; i++) {
        if (i == 0) fout << A[i];
        else fout << " " << A[i];
    }
    return 0;
}