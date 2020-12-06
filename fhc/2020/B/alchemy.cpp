#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    ifstream fin ("alchemyfinal.txt");
    ofstream fout ("bfinalout.txt");
    int tc; 
    fin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, acnt = 0, bcnt = 0;
        fin >> n;
        string s;
        fin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                acnt++;
            }
            else {
                bcnt++;
            }
        }
        if (abs(bcnt-acnt) == 1) {
            fout << "Case #" << t << ": " << 'Y' << endl;
        }
        else {
            fout << "Case #" << t << ": " << 'N' << endl;
        }
    }
    return 0;
}