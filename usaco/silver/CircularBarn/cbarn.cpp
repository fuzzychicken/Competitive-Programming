#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int n;
int cows[MAXN];

int main() {
    ifstream fin ("cbarn.in");
    ofstream fout ("cbarn.out");
    
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> cows[i];
    }

    int ans = 2e9;
    for (int i = 0; i < n; i++) {
        int rot[n];
        for (int j = 0; j < n; j++) {
            rot[j] = cows[(i + j) % n];
        }

        int spacesNeeded = 0;
        bool valid = true;
        for (int j = n - 1; j >= 0; j--) {
            spacesNeeded += rot[j];
            // if spacesNeeded is more than spacesAvailable
            if (spacesNeeded > n - j) { 
                valid = false;
                break;
            }
        } 

        if (!valid) {
            continue;
        }

        int lastZero = n - 1;
        for (int j = lastZero; j >= 0; j--) {
            if (rot[j] == 0) {
                lastZero = j;
                break;
            }
        }
        
        int prev = -1;
        int energy = 0;
        for (int j = n - 1; j >= 0; j--) {
            // have cows to remove, the lastZero is after the currentIdx, 
            // haven't reached top of the rot
            while (rot[j] > 0 && lastZero >= j && lastZero != prev) {
                rot[j]--;
                rot[lastZero]++;
                energy += (lastZero - j) * (lastZero - j);

                // update the lastZero
                prev = lastZero;
                for (int k = lastZero - 1; k >= 0; k--) {
                    if (rot[k] == 0) {
                        lastZero = k;
                        break;
                    }
                }
            }
        }
        ans = min(ans, energy);
    }
    fout << ans << '\n';
    return 0;
}

// if a cow1 passes the starting pt of cow2, then end pt of cow2 > cow1
