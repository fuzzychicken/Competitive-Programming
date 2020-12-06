#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, a;
    cin >> n >> m >> a;
    long long cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i += a) {
        cnt++;
    }
    for (int i = 0; i < m; i += a) {
        cnt2++;
    }
    cout << cnt * cnt2 << '\n';
    return 0;
}