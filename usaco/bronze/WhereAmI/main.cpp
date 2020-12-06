#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int N;
string c;

int main() {
    ifstream fin ("whereami.in");
    ofstream fout ("whereami.out");
    fin >> N;
    fin >> c;
    for (int i = 1; i <= N; i++) {
        set<string> s;
        int cnt = 0;
        for (int j = 0; j < N-i+1; j++) {
            if (s.count(c.substr(j, i)) > 0) cnt++;
            s.insert(c.substr(j, i));
        }
        if (cnt == 0) {
            fout << i << "\n";
            return 0;
        } 
    }
    return 0;
}