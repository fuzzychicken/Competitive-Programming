#include <iostream>
#include <fstream>
using namespace std;

int N, K;

int main() {
    ifstream fin ("word.in");
    ofstream fout ("word.out");
    fin >> N >> K;
    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < N; i++) {
        string s;
        fin >> s;
        if (cnt + s.length() <= K) {
            if (idx == 0)
                fout << s;
            else 
                fout << " " << s;
            idx++;
            cnt += s.length();
        }
        else {
            idx = 1;
            fout << "\n" << s;
            cnt = s.length();
        }
    }
    fout << "\n";
    return 0;
}