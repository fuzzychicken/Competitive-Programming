//
//  main.cpp
//  TheGreatRevegetation
//
//  Created by Henry Chen on 6/30/20.
//  Copyright © 2020 Henry Chen. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("revegetate.in");
    ofstream fout ("revegetate.out");
    int N, M;
    int A[150], B[150], G[100];
    fin >> N >> M;
        
    for (int i = 0; i < M; i++) {
        fin >> A[i] >> B[i];
        if (A[i] > B[i]) swap(A[i], B[i]);
    }
        
    for (int i = 1; i <= N; i++) {
        int g;
        for (g = 1; g <= 4; g++) {
            bool ok = true;
            for (int j = 0; j < M; j++)
                if (B[j] == i && G[A[j]] == g)
                    ok = false;
            if (ok) break;
        }
        G[i] = g;
        fout << g;
    }
    fout << "\n";
    return 0;
}
