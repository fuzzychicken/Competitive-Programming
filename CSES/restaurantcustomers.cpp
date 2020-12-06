#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        a[f]++, a[s]--;
    }
    int cnt = 0, ans = 0;
    for (auto p : a) {
        cnt += p.second;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
