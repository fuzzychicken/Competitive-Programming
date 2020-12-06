#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin ("leapfrog_ch__input.txt");
    ofstream fout ("output.txt");
    int t; 
    fin >> t;
    for (int i = 1; i <= t; i++) {
        string s;
        fin >> s;
        int Aidx = 0, Bcnt = 0, num = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'A') {
                Aidx = j; 
            }
            if (s[j] == 'B') {
                Bcnt++;
            }
        }
        num = s.length() - 1;
        if (num <= Bcnt * 2 && Bcnt != num) {
            fout << "Case #" << i << ": " << "Y" << endl;
        }
        else {
            fout << "Case #" << i << ": " << 'N' << endl;
        }
    }
    return 0;
}