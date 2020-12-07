#include <bits/stdc++.h>
using namespace std;


int findidx(double target, vector<double> frequency) {
    for (int i = 0; i < frequency.size(); i++) {
        if (frequency[i] == target)
            return i;
    }
    return -1;
}


double gogo(double second, vector<double> preset, int idxSecond, vector<double> frequency) {
    int curmin = INT_MAX;
    double ret;
    for (double i : preset) {
        int abcc = abs(findidx(i, frequency)-idxSecond);
        if (abcc < curmin) {
            curmin = abcc;
            ret = i;
        }
    }
    // cout << "RET: " << ret << '\n';
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int c;
    cin >> c;
    for (int pp = 1; pp <= c; pp++) {
        int n, p, s;
        cin >> n >> p >> s;
        vector<double> frequency(n);
        for (int i = 0; i < n; i++) {
            cin >> frequency[i];
        }
        vector<double> preset;
        for (int i = 0; i < p; i++) {
            double aaaa; cin >> aaaa;
            preset.push_back(aaaa);
        }

        cout << "Day #" << pp << ":" << '\n';
        
        for (int i = 0; i < s; i++) {
            int idxFirst, idxSecond;
            
            double first, second;
            cin >> first >> second;
            // 0 indexed
            // idxFirst = lower_bound(frequency.begin(), frequency.end(), first) -frequency.begin();
            // idxSecond = lower_bound(frequency.begin(), frequency.end(), second) -frequency.begin();
            idxFirst = findidx(first, frequency);
            idxSecond = findidx(second, frequency);
            int noSkipDist = min(abs(idxSecond-idxFirst), min(abs(idxFirst+1 + (n-idxSecond-1)), abs(n-1-idxFirst) + 1 + idxSecond));

            // double skipTo1 = preset[lower_bound(preset.begin(), preset.end(), second)-preset.begin()];
            // double skipTo2 = preset[upper_bound(preset.begin(), preset.end(), second)-preset.begin()];

            // cout << skipTo1 << ' ' << skipTo2 << '\n';

            // double skipTo = min(abs(skipTo1-second), abs(skipTo1-second));
            double skipTo = gogo(second, preset, idxSecond, frequency);
            // int idxSkippedTo = lower_bound(frequency.begin(), frequency.end(), skipTo) -frequency.begin();
            int idxSkippedTo;
            int skipDist = INT_MAX;

            for (double x : preset) {
                idxSkippedTo = findidx(x, frequency);
                skipDist = min(skipDist,1+min(abs(idxSkippedTo-idxSecond),n-abs(idxSkippedTo-idxSecond)));
            }
        

            int ans = min(skipDist, noSkipDist);
            cout << ans << '\n';
            
        }
        cout << '\n';
    }
}
