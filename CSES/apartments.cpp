#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &i : a) 
        cin >> i;
    for (int &i : b) 
        cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p1 = 0, p2 = 0, ans = 0;
    while (p1 < n && p2 < m) {
        if (a[p1] - b[p2] > k) {
            p2++;
        } else if (b[p2] - a[p1] > k) {
            p1++; 
        } else {
            p1++;
            p2++;
            ans++;
        }
    }
    cout << ans << '\n';
}
