#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n;
int coord[100000][2], c[100000], pos[100000], neg[100000];

bool cmp(int i, int j) {
    if (neg[i] == neg[j]) {
        return pos[i] > pos[j];
    }
    return neg[i] < neg[j];
}

int main() {
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> coord[i][0] >> coord[i][1];
        pos[i] = coord[i][0] + coord[i][1];
        neg[i] = coord[i][0] - coord[i][1];
        c[i] = i;
    }
    sort(c, c+n, cmp);
    int maxmx = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (pos[c[i]] > maxmx) {
            cnt++;
            maxmx = pos[c[i]];
        }
    }
    fout << cnt << "\n";
    return 0;
}