#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    /* freopen("template.in","r",stdin); */
    /* freopen("template.out","w",stdout); */
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << "HELLO\n";
        } else {
            cout << "bill\n";
        }
    }
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            sort(a.begin(), a.end(), [](int a, int b) {
                return a < b;
            });
        }
    }
    cout << "HERE" << '\n';
    return 0;
}

