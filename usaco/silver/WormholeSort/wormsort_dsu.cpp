#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> par, P;
vector<array<int, 3>> wh;

int find(int x) {
    if(x == par[x]) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int a, int b) { 
    int c = find(a); 
    int d = find(b); 
    if(c != d) {
        par[d] = c; 
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    
    cin >> n >> m;
    par.resize(n+1);
    P.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
        par[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        /* a--, b--; */
        wh.push_back({a,b,w});
    }

    sort(wh.begin(), wh.end(), [](array<int, 3> a, array<int, 3> b) {
        return a[2] > b[2];
    });
   
    int w = -1;
    for (int i = 1; i <= n; i++) {
        while (find(i) != find(P[i])) {
            w++;
            unite(wh[w][0], wh[w][1]);
        }
    }
    if (w == -1) cout << w << '\n';
    else cout << wh[w][2] << '\n';
}
