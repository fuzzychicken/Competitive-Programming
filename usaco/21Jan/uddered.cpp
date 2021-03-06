#include <bits/stdc++.h>
using namespace std;

string alphabet, word;
int loc[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> alphabet >> word;
    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < alphabet.size(); j++) {
            if (alphabet[j] == word[i]) {
                loc[i] = j;
            }
        }
    }
    int cnt = 1;
    for (int i = 0; i < word.size()-1; i++) {
        if (loc[i+1] <= loc[i]) cnt++;
    }
    cout << cnt << endl;
}
