#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 1;

int n;
long long prefix[MAXN];
int first[7], last[7];

int main() {
    ifstream fin ("div7.in");
    ofstream fout ("div7.out");
    fin >> n;
    // prefix[0] = 0;
    for (int i = 0; i < 7; i++) {
        first[i] = INT32_MAX;
    }

    int currPref = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        fin >> a;
        currPref += a;
        currPref %= 7;
        first[currPref] = min(first[currPref], i);
        last[currPref] = i;
        // prefix[i] = prefix[i-1] + a;
    }

    int best = 0;
    for (int i = 0; i < 7; i++) {
        best = max(best, (last[i] - first[i]));
    }
    // for (int i = n; i >= 0; i--) {
    //     for (int j = 0; j <= n-i; j++) {
    //         if ((prefix[j + i] - prefix[j]) % 7 == 0) {
    //             fout << i << endl;
    //             return 0;
    //         }
    //     }
    // }
    fout << best << "\n";
    return 0;
}