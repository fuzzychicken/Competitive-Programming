#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;

int n, q;
int order[MAXN], H[MAXN], G[MAXN], J[MAXN];

int main() {
    ifstream fin ("bcount.in");
    ofstream fout ("bcount.out");
    fin >> n >> q;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {   
            order[i] = 0;
            H[i] = 0;
            G[i] = 0;
            J[i] = 0;
            continue;
        }
        int a;
        fin >> a;
        order[i] = a;
        if (order[i] == 1) {
            H[i] = H[i-1] + 1;
            G[i] = G[i-1];
            J[i] = J[i-1];
        }
        else if (order[i] == 2) {
            G[i] = G[i-1] + 1;
            H[i] = H[i-1];
            J[i] = J[i-1];
        }
        else {
            J[i] = J[i-1] + 1;
            H[i] = H[i-1];
            G[i] = G[i-1];
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> b >> a;
        fout << H[a] - H[b-1] << " ";
        fout << G[a] - G[b-1] << " ";
        fout << J[a] - J[b-1] << endl;
    }
    return 0;
}