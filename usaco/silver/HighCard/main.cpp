#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> bessie, elsie;

int main() {
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        elsie.push_back(x);
    }
    sort(elsie.begin(), elsie.end());
    for (int i = 1; i <= 2 * n; i++) {
        if (!binary_search(elsie.begin(), elsie.end(), i)) {
            bessie.push_back(i);
        }
    }
    int cnt = 0;
    int idx = 0;
    int idx2 = 0;
    for (int i = 0; i < n; i++) {
        if (idx >= n) {
            break;
        }
        if (bessie[idx] > elsie[idx2]) {
            cnt++;
            idx++;
            idx2++;
        }
        else {
            idx++;
        }
    }
    fout << cnt << "\n";
    return 0;
}
