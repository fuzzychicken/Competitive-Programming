#include <bits/stdc++.h>
using namespace std;

int n;
int64_t tot = 0;
vector<int64_t> a;

bool ok(int64_t mid) {
    if ((tot + mid) % (n-1) == 0) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T; cin >> T;

    while (T--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tot += a[i];
        }
        int64_t lo = 0, hi = 1e18;
        int64_t ans = 0;
        while (lo <= hi) {
            int64_t mid = (lo + hi) / 2
;            if (ok(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
