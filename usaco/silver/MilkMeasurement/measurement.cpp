#include <bits/stdc++.h>
using namespace std;

struct measurement {
	int day, id, change;
};

int n, g;
vector<measurement> measurements;
map<int, int> cows;

vector<int> update() {
	int max = 0;
	vector<int> idxs;
	for (auto t : cows) {
		if (t.second > max) {
			max = t.second;
		}
	}
	for (auto t : cows) {
		if (t.second == max) {
			idxs.push_back(t.first);
		}
	}
	return idxs;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);
	cin >> n >> g;
	for (int i = 0; i < n; i++) {
		int day, id, change;
		cin >> day >> id >> change; 
		measurements.push_back({day, id, change});
		cows[id] = g;
	}
	sort(measurements.begin(), measurements.end(), [](measurement a, measurement b) {
		return a.day < b.day;
	});
	set<int> leaderboard;
	int changes = 0;
	for (measurement t : measurements) {
		if (leaderboard.size() == 0) {
			if (cows[t.id] + t.change > g) {
				leaderboard.insert(t.id);
				changes++;
			}
		}	
		if (cows[t.id] + t.change > cows[*leaderboard.begin()]) {
			set<int> prev = leaderboard;
			leaderboard.clear();
			leaderboard.insert(t.id);
			if (leaderboard != prev) changes++;
		}
		else if (cows[t.id] + t.change == cows[*leaderboard.begin()]) {
			set<int> prev = leaderboard;
			leaderboard.insert(t.id);
			if (leaderboard != prev) changes++;
		}
		else if (cows[t.id] + t.change < cows[*leaderboard.begin()] && leaderboard.find(t.id) != leaderboard.end()) {
			set<int> prev = leaderboard;
			cows[t.id] += t.change;
			vector<int> updated = update();
			leaderboard.clear();
			for (int b : updated) {
				leaderboard.insert(b);
			}
			if (leaderboard != prev) changes++;
			continue;
		}
		cows[t.id] += t.change;
	}
	cout << changes << '\n';
	return 0;
}
