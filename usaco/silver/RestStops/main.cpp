#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int64_t l, n, rf, rb;
vector<pair<int64_t,int64_t>> v;

bool cmp(pair<int64_t,int64_t> a, pair<int64_t,int64_t> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ifstream fin ("reststops.in");
    ofstream fout ("reststops.out");
    fin >> l >> n >> rf >> rb;
    for (int64_t i = 0; i < n; i++) {
        int64_t x, c;
        fin >> x >> c;  
        v.push_back({x, c});
    }
    sort(v.begin(), v.end(), cmp);
    int64_t farmertime = 0, bessietime = 0, waittime = 0, tastepts = 0, currtime = -1;
    for (pair<int64_t,int64_t> i : v) {
        farmertime = i.first * rf;
        bessietime = i.first * rb + waittime;
        int64_t diff = farmertime - bessietime;
        tastepts += diff * i.second;
        waittime += diff;
        currtime = i.first;
    }
    fout << tastepts << endl;
    return 0;
}