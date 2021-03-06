#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a=1, b=1;
    for (int i = 1; i < (int)s.size(); i++)  {
        if (s[i] > s[i-1]) 
            a = b+1;
        else if (s[i] < s[i-1])
            b = a+1;
    }
    cout << max(a,b) << endl;
}
