#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    int p1 = 0, p2 = n-1;
    while (p1 < p2) {
        if (a[p1].first + a[p2].first == x) {
            cout << a[p1].second << ' ' << a[p2].second << '\n';
            exit(0);
        } else if (a[p1].first + a[p2].first < x) {
            p1++;
        } else {
            p2--;
        }
    }
    cout << "IMPOSSIBLE\n";
}
