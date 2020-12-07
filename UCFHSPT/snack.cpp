#include <bits/stdc++.h>
using namespace std;

int numvowels(string s) {
    int cnt = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c== 'o' || c=='u') {
            cnt++;
        }
        else if (c == 'y') {
            cnt+=2;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    /* freopen("template.in","r",stdin); */
    /* freopen("template.out","w",stdout); */
    int c;
    cin >> c;

    for (int i = 1; i <= c; i++)  {
        int s; cin >> s;
        vector<pair<string, int>> mp;
        for (int i = 0; i < s; i++) {
            string ss; cin >> ss;
            mp.push_back({ss, numvowels(ss)});
        }
        sort(mp.begin(), mp.end(), [](pair<string, int> a, pair<string,int> b) {
            if (a.second == b.second) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        });
        cout << "Cabinet #" << i << ":" << '\n';
        for (auto a : mp) {
            cout << a.first << '\n';
        }
        cout << '\n';
    }
    return 0;
}

