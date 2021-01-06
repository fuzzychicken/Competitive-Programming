#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("cereal.in","r",stdin); 
    // freopen("cereal.out","w",stdout);

    int n, m;
    cin >> n >> m;

    unordered_set<int> types;
    for (int i = 1; i <= m; i++) {
        types.insert(i);
    }

    int pref[n+1];
    pref[0] = 0;

    vector<pair<int, int>> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i].first >> q[i].second;
    }

    for (int i = 1; i <= n; i++) {
        auto it1 = types.find(q[n-i].first);
        int add = 0;
        if (it1 != types.end()) {
            add = 1;
            types.erase(it1);
        } else {
            auto it2 = types.find(q[n-i].second);
            if (it2 != types.end()) {
                add = 1;
                types.erase(it2);
            }
        }
        pref[i] = pref[i-1] + add;
    }

    for (int i = n; i >= 1; i--) {
        cout << pref[i] << '\n';
    }
    return 0;
}

