#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h = n/2;
    int cnt = log2(h);
    cnt += h-pow(2,cnt);
    cnt++;
    if (n % 2 == 1) cnt++;
    cout << cnt << endl;

    for (int j = 0; j < n; j++)  {

    }
}
