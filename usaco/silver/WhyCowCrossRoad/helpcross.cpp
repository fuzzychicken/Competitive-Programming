#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int c, n;
vector<int> t;
vector<pair<int, int>> ab;

bool cmp(pair<int, int> x, pair<int, int> y) {
    if (x.second == y.second) {
        return x.first < y.first;
    }
    return x.second < y.second;
}

int main() {
    ifstream fin ("helpcross.in");
    ofstream fout ("helpcross.out");
    fin >> c >> n;
    for (int i = 0; i < c; i++) { 
        int a;
        fin >> a;
        t.push_back(a);
    }
    sort(t.begin(), t.end()); 
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        ab.push_back({a, b});
    }
    sort(ab.begin(), ab.end(), cmp);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        auto chicken = lower_bound(t.begin(), t.end(), ab[i].first);
        if (chicken != t.end() && *chicken <= ab[i].second) {
            cnt++;
            t.erase(chicken);
        }
    }
    fout << cnt << endl;
    return 0;
}

/* use last ending time not beginning time for the correct greedy solution */