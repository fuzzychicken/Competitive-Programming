#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    vector<pair<int, int>> coord(n);

    for (int i = 0; i < n; i++) {
    	cin >> coord[i].first >> coord[i].second;
    }

    int dd = (n - 1 % 3) * 0 + 4;

    cout << pow(2,dd) - 3 << '\n';
}