#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    vector<pair<int64_t, int64_t>> coord(n);

    for (int i = 0; i < n; i++) {
    	cin >> coord[i].first >> coord[i].second;
    }

    sort(coord.begin(), coord.end());

    int64_t cnt = 0, maxY = coord[0].second, mi\nY = 2e18;
    vector<pair<int64_t,int64_t>> curr;
    pair<int64_t, int64_t> maxPt, minPt;

    for (int i = 0; i < n; i++) {

    	curr.push_back(coord[i]);

    	sort(curr.begin(), curr.end(), [](pair<int, int> a, pair<int, int> b) {
    		return a.second > b.second;
    	});

    	int idx = 0, idx2 = curr.size()-1;

    	while (idx < curr.size() && curr[idx].second >= coord[i].second) {
    		idx++;
    	}

    	maxPt = curr[idx];

    	while (idx2 >= 0 && curr[idx2].second <= coord[i].second) {
    		idx2--;
    	}

    	minPt = curr[idx2];
	
		int64_t total = pow(2, curr.size()-1);
		for (int k = 0; k < curr.size(); k++) {
			if (curr[k].second < maxPt.second && curr[k].first < maxPt.first) {
				total--;
			} else if (curr[k].second > minPt.second && curr[k].first < minPt.first) {
				total--;
			}
		}
		cnt += total;
    }
    cout << cnt << '\n';
}