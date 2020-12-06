#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int b[2], r[2], l[2];

int main() {
    ifstream fin ("buckets.in");
    ofstream fout ("buckets.out");
    
    for (int i = 0; i < 10; i++) {
        string s;
        fin >> s;
        for (int j = 0; j < 10; j++) {
            if (s[j] == 'B') {
                b[0] = j;
                b[1] = i;
            }
            if (s[j] == 'R') {
                r[0] = j;
                r[1] = i;
            }
            if (s[j] == 'L') {
                l[0] = j;
                l[1] = i;
            }
        }
    }
    int ans = abs(l[1] - b[1]) + abs(l[0] - b[0]) - 1;
    if (b[0] == r[0] && r[0] == l[0]) {
        if ((r[1] > b[1] && r[1] < l[1]) || (r[1] < b[1] && r[1] > l[1]))
            ans += 2;
    }
    if (b[1] == r[1] && r[1] == l[1]) {
        if ((r[0] > b[0] && r[0] < l[0]) || (r[0] < b[0] && r[0] > l[0]))
            ans += 2;
    }
    fout << ans << "\n";
    return 0;
}