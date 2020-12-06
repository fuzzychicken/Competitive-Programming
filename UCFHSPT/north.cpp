#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    /* freopen("template.in","r",stdin); */
    /* freopen("template.out","w",stdout); */

    int d;
    cin >> d;
    map<string, double> mp;
    mp["N"] = 0.0d;
    mp["S"] = 180.0d;
    mp["E"] = 90.0d;
    mp["W"] = 270.0d;
    mp["NE"] = 45.0d;
    mp["NNE"] = 22.5d;
    mp["ENE"] = 67.5d;
    mp["ESE"] = 112.5d;
    mp["SE"] = 135.0d;
    mp["SSE"] = 157.5d;
    mp["SSW"] = 202.5d;
    mp["SW"] = 225.0d;
    mp["WSW"] = 247.5d;
    mp["WNW"] = 292.5d;
    mp["NW"] = 315.0d;
    mp["NNW"] = 337.5d;
    while (d--) {
        string x;
        cin >> x;
        // printf("%s is %.1f degrees\n", x.c_str(), mp[x]);
        cout << fixed << setprecision(1) << x << " is " << mp[x] << " degrees" << '\n';
    }
    return 0;
}

