#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int n, m, c;
int arrival[MAXN];

bool check(int mid) {
    int minElement = arrival[0];
    int bus = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arrival[i] - minElement <= mid && cnt < c) {
            cnt++;
        }
        else {
            bus++;
            minElement = arrival[i];
            cnt = 1;
        }
    }
    return (bus <= m);
}

int main() {
    ifstream fin ("convention.in");
    ofstream fout ("convention.out");
    fin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        fin >> arrival[i];
    }
    sort(arrival, arrival + n);
    int lo = 0;
    int hi = arrival[n-1] + 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (!check(mid)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
            ans = mid;
        }
    }
    fout << ans << '\n';
    return 0;
}