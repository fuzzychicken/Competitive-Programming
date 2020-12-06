#include <iostream>
#include <fstream>
using namespace std;

int N, K, A1, A2, B1, B2;
int final[101];

int next_pos(int i) {
    if (i >= A1 && i <= A2) i = A1+A2-i;
    if (i >= B1 && i <= B2) i = B1+B2-i;
    return i;
}

int main() {
    ifstream fin ("swap.in");
    ofstream fout ("swap.out");
    fin >> N >> K >> A1 >> A2 >> B1 >> B2;
    for (int i = 1; i <= N; i++) {
        int cnt = 1;
        int cur = next_pos(i);
        while (cur != i) {
            cnt++;
            cur = next_pos(cur);
        }
        int k = K % cnt;
        for (int j = 0; j < k; j++) {
            cur = next_pos(cur);
        }
        final[cur] = i;
    }
    for (int i = 1; i <= N; i++) {
        fout << final[i] << "\n";
    }
    return 0;
}