#include <iostream>
#include <string>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int idx = 0;
        for (int i = 0; i < (s.length() / 2); i++) {
            cout << s[idx];
            idx += 2;
        }
        cout << s[s.length()-1] << endl;
    }
}