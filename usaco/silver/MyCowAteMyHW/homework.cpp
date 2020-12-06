#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+1;

int n;
int questions[MAXN], prefix[MAXN], mine[MAXN];

int main() {
    ifstream fin ("homework.in");
    ofstream fout ("homework.out");
    fin >> n;
    questions[0] = 0;
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        fin >> questions[i];
        prefix[i] = prefix[i-1] + questions[i];
    }

    mine[n] = questions[n];
    for (int i = n-1; i >= 0; i--) {
        mine[i] = min(mine[i+1], questions[i]);
    }

    double best = 0;
    vector<pair<int, double>> ans1;
    for (int i = 1; i <= n-2; i++) {
        double avg = (prefix[n] - prefix[i] - mine[i]) / (double)(n-i-1);
        if (avg >= best) {
            best = avg;
            ans1.push_back({i, best});
        }
    }
    
    for (auto& e : ans1) {
        if (e.second == best) {
            fout << e.first << '\n';
        }
    }
    return 0;
}
