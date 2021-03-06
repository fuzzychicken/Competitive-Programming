#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> g(n);
    for (int i = 0; i < n; i++) 
        cin >> g[i];
    sort(g.begin(), g.end());
    for (int i = 0; i < n; i++) {
        cout << g[i] << ' ';
    }
}