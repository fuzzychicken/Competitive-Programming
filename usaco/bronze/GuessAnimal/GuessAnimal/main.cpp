#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n;
vector<string> ch[100];

int common(int a, int b) {
    int cnt = 0;
    vector<string> &v1 = ch[a], &v2 = ch[b];
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] == v2[j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    ifstream cin ("guess.in");
    ofstream cout ("guess.out");
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> s >> k;
        for (int j = 0; j < k; j++) {
            cin >> s;
            ch[i].push_back(s);
        }
    }
    int maxe = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            maxe = max(common(i, j), maxe);
        }
    }
    cout << maxe + 1 << '\n';
    return 0;
}
