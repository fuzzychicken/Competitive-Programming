#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, mine[100000], maxe[100000];
pair<int, int> coord[100000];

int main() {
    ifstream fin ("moop.in");
    ofstream fout ("moop.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> coord[i].first >> coord[i].second;
    }
    sort(coord, coord+n);
    mine[0] = coord[0].second;
    for (int i = 1; i < n; i++) {
        mine[i] = min(mine[i-1], coord[i].second);
    }
    maxe[n-1] = coord[n-1].second;
    for (int i = n-2; i >= 0; i--) {
        maxe[i] = max(maxe[i+1], coord[i].second);
    }
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (mine[i] > maxe[i+1]) {
            cnt++;
        }
    }
    fout << cnt+1 << endl;
    return 0;
}