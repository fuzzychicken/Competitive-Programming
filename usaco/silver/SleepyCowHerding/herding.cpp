#include <bits/stdc++.h>
using namespace std;

int n;
int loc[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("herding.in", "r", stdin);
    // freopen("herding.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> loc[i];
    }
    sort(loc, loc + n);
}