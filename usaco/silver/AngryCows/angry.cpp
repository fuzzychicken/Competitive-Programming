#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4;

int n, k;
int loc[MAXN];

bool works(int mid) {
    int cnt = 0;
    int i = 0;
    while (i < n) {
        cnt++;
        int center = loc[i] + mid;
        int idx = i;
        while (idx < n && loc[idx] <= (center + mid)) {
            idx++;
        }
        if (idx == i) {
            i++;
        }
        else {
            i = idx;
        }       
    }
    return (cnt <= k);
}

int main() {
    ifstream fin ("angry.in");
    ofstream fout ("angry.out");
    fin >> n >> k;
    for (int i = 0; i < n; i++) {
        fin >> loc[i];
    }
    sort(loc, loc+n);

    // Binary Search on Answer
    int lo = 0, hi = loc[n-1], ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (works(mid)) {
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    fout << ans << '\n';
    return 0;
}
