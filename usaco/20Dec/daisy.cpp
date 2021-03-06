#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> petals(n);
    for (int i = 0; i < n; i++) {
        cin >> petals[i];
    }    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += petals[k];
            }
            double avg = double(sum) / (j-i+1);
            bool ok = true;
            // cerr << i << ' ' << j << ' ' << sum << ' ' << avg << endl;
            for (int k = i; k <= j; k++) {
                if (double(petals[k]) == avg) {
                    cnt++;
                    ok = false;
                }
                if (!ok) break;
            }
        }
    }
    cout << cnt << '\n';
}
