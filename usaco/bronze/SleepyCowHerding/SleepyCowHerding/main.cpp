//
//  main.cpp
//  SleepyCowHerding
//
//  Created by Henry Chen on 6/30/20.
//  Copyright © 2020 Henry Chen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

int loc[3];

int main() {
    ifstream fin ("herding.in");
    ofstream fout ("herding.out");
    for (int i = 0; i < 3; i++) fin >> loc[i];
    sort(loc, loc+3);
    int mine = min((loc[1] - loc[0]), (loc[2] - loc[1])) - 1;
    int maxe = max((loc[1] - loc[0]), (loc[2] - loc[1])) - 1;
    if (mine == 0) mine = 2;
    if (mine > 2) mine = 2;
    if (maxe == 0) {
        mine = 0;
        maxe = 0;
    }
    fout << mine << '\n';
    fout << maxe << '\n';
    return 0;
}
