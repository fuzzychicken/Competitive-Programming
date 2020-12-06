#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin ("travelin.txt");
    ofstream fout ("traveloutput.txt");
    int tc; 
    fin >> tc;
    for (int i = 1; i <= tc; i++) {
        int n;
        fin >> n;
        string in, out;
        fin >> in >> out;
        fout << "Case #" << i << ": " << endl;
        for (int j = 0; j < n; j++) {
            for (int u = 0; u < n; u++) {
                if (j == u) {
                    fout << 'Y';
                    continue;
                }
                char dep, arr;
                bool ok = true;
                if (u > j) {
                    for (int k = j; k < u; k++) {
                        dep = out[k];
                        arr = in[k+1];
                        if (arr == 'N' || dep == 'N') {
                            ok = false;
                        }
                    }
                }
                else {
                    for (int k = j; k > u; k--) {
                        dep = out[k];
                        arr = in[k-1];
                        if (arr == 'N' || dep == 'N') {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    fout << 'Y';
                }
                else {
                    fout << 'N';
                }
            }
            fout << endl;
        }
    }
    return 0;
}
