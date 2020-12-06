#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int n, comp = 0;
int cows[MAXN], visited[MAXN];

int find(int i) {
    if (i == 0) {
        return 1;
    }
    if (i == n-1) {
        return n-2;
    }
    int rightDiff = cows[i+1] - cows[i];
    int leftDiff = cows[i] - cows[i-1];
    if (rightDiff < leftDiff) {
        return i+1;
    }
    // leftDiff <= rightDiff
    return i-1;
}

int main() {
    ifstream fin ("hoofball.in");
    ofstream fout ("hoofball.out");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> cows[i];
    }
    sort(cows, cows+n);
    for (int i = 0; i < n; i++) {
        visited[find(i)]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            cnt++;
        }
        // pass only between pair
        if (i > find(i) && i == find(find(i)) && visited[find(i)] == 1 && visited[i] == 1) { 
            cnt++;
        }
    }
    fout << cnt << "\n";
    return 0;
}