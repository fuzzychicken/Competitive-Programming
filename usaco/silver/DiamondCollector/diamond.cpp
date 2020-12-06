#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000;

int n, k;
int a[MAXN], num[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        int inc = 0;
        while (true) {
            if (i+inc > n-1) break;
            if (a[i+inc] - a[i] <= k) {
                num[i]++;
                inc++;
            }
            else {
                break;
            }
        }
    }
    int maxe = -1;
    for (int i = 0; i < n; i++) {
        if (num[i] > maxe) {
            maxe = num[i];
        }
    }
    vector<int> maxidxs;
    for (int i = 0; i < n; i++) {
        if (num[i] == maxe) maxidxs.push_back(i);
    }
    long long ans = 0;
    for (int d : maxidxs) {
        int temp[n];
        for (int i = 0; i < n; i++) {
            temp[i] = num[i];
        }
        for (int i = d; i < d+maxe; i++) {
            temp[i] = -10;
        }
        // re-adjust 
        for (int i = 0; i < n; i++) {
            if (d <= i) continue;
            if (d-i < temp[i]) temp[i] = d-i;
        }
        int max2 = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] == -10) continue;
            max2 = max(max2, temp[i]);
        }
        ans = max((long long) (max2+maxe), ans);
        // cout << "ans: " << ans << '\n';
    }
    // for (int i = 0; i < n; i++) {
    //     int temp[n];
    //     for (int j = 0; j < n; j++) {
    //         temp[j] = num[j];
    //     }
    //     int a = temp[i];
    //     for (int j = i; j < (i + a); j++) {
    //         temp[j] = -10;
    //     }
    //     for (int j = 0; j < n; j++) {
    //         if (i <= j) continue;
    //         if (i - j < temp[j]) temp[j] = i -j;
    //     }
    //     int max2 = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (temp[j] == -10) continue;
    //         max2 = max(max2, temp[j]);
    //     }
    //     ans = max((long long) (max2+num[i]), ans);
    // }
    cout << ans << '\n';
    return 0;
}