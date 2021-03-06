#include <bits/stdc++.h>
using namespace std;

int64_t n;

bool check(int64_t mid) {
    int64_t ans = mid - (mid/3) - (mid/5) + (mid/15);
    return ans <= n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef LOCAL
    freopen("moobuzz.in","r",stdin);
    freopen("moobuzz.out","w",stdout);
    #endif

    cin >> n;

    int64_t lo = 0, hi = 2e18, ret;
    while (lo <= hi) {
        int64_t mid = (lo+hi)/2;
        // cerr << "MID " << mid << endl;
        if (check(mid)) {
            lo = mid+1;
            ret = mid; 
        } else {
            hi = mid-1;
        }
    }

    while (ret % 3 == 0 || ret % 5 == 0) {
        ret--;
    }
    cout << ret << '\n';
}