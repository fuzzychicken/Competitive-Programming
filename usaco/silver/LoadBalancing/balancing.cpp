#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int n;
int x[MAXN], y[MAXN];
vector<pair<int, int>> coord;

int main() {
    ifstream fin ("balancing.in");
    ofstream fout ("balancing.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
        coord.push_back({x[i], y[i]});
    }
    sort(x, x + n);
    sort(y, y + n);

    int ans = 2e9;
    for (int i = 0; i < n; i++) {
        int vertical = x[i] + 1;
        for (int j = 0; j < n; j++) {
            int horizontal = y[i] + 1;
            int m = 0;
            int one = 0, two = 0, three = 0, four = 0;
            for (auto& p : coord) {
                int x = p.first, y = p.second;
                if (x > vertical && y > horizontal) {
                    one++;
                }
                else if (x < vertical && y > horizontal) {
                    two++;
                }
                else if (x < vertical && y < horizontal) {
                    three++;
                }
                else {
                    four++;
                }
            }
            m = max(one, max(two, max(three, four)));
            ans = min(m, ans);
        }
    }
    fout << ans << '\n';
    return 0;
}
