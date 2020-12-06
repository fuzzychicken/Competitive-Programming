#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;

int n, tmax;
int d[MAXN];

bool works(int mid) {
    int timeToFinish = 0;
    vector<int> q;
    for (int i = 0; i < n; i++) {
        if ((int) q.size() == mid) {
            auto min = min_element(q.begin(), q.end());
            timeToFinish = *min;
            q.erase(min);
        }
        if (timeToFinish + d[i] > tmax) {
            return false;
        }
        q.push_back(timeToFinish + d[i]);
    }
    return true;
}

int main() {
    ifstream fin ("cowdance.in");
    ofstream fout ("cowdance.out");
    fin >> n >> tmax;
    for (int i = 0; i < n; i++) { 
        fin >> d[i];
    }
    int lo = 0, hi = 1e9, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (works(mid)) {
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    fout << ans << '\n';
    return 0;
}
