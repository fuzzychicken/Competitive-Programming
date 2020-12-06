#include <bits/stdc++.h>
using namespace std;

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << to_string(h); if (sizeof...(t)) cerr << ", ";DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
    #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif

const int MAXN = 50000;

int N;
vector<pair<int, int>> coord, test;

int sz(vector<pair<int, int>> test) {
    int cnt = 0;
    for (auto& i : test) {
        cnt++;
    }
    return cnt;
}

bool cmp1(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

vector<pair<int, int>> generate(vector<pair<int, int>> test, vector<pair<int, int>> coord) {
    for (int i = 0; i < 6; i++) {
        if (i <= 2 && find(test.begin(), test.end(), coord[i]) == test.end()) {
            test.push_back(coord[i]);
        }
        else if (i > 2 && find(test.begin(), test.end(), coord[N-1+(i-5)]) == test.end()) {
            test.push_back(coord[N-1+(i-5)]);
        }
    }
    return test;
}

long long getArea(vector<pair<int, int>> test, int i, int j, int k) {
    long long area = LLONG_MAX;
    long long minx = LLONG_MAX;
    long long miny = LLONG_MAX;
    long long maxx = LLONG_MIN;
    long long maxy = LLONG_MIN;
    for (int inc = 0; inc < sz(test); inc++) {
        if (inc == i || inc == j || inc == k) 
            continue;
        minx = min(minx, (long long) test[inc].first);
        maxx = max(maxx, (long long) test[inc].first);
        miny = min(miny, (long long) test[inc].second);
        maxy = max(maxy, (long long) test[inc].second);
    }
    area = (maxx-minx) * (maxy-miny);
    return area;
}

int main() {
    ifstream fin ("reduce.in");
    ofstream fout ("reduce.out");
    fin >> N;
    coord.resize(N);
    for (int i = 0; i < N; i++) {
        fin >> coord[i].first >> coord[i].second;
    }
    sort(coord.begin(), coord.end(), cmp1);
    test = generate(test, coord);
    test.insert(test.begin(), coord[3]);
    test.insert(test.begin()+1, coord[N-4]);

    sort(coord.begin(), coord.end(), cmp2);
    for (auto& i : coord) {
        dbg(i.first, i.second);
    }
    test = generate(test, coord);
    test.insert(test.begin()+2, coord[3]);
    test.insert(test.begin()+3, coord[N-4]);

    long long area = LLONG_MAX;

    for (int i = 4; i < sz(test); i++) {
        for (int j = i + 1; j < sz(test); j++) {
            for (int k = j + 1; k < sz(test); k++) {
                area = min(area, getArea(test, i, j, k));
            }
        }
    }

    fout << area << '\n';
    return 0;
}
