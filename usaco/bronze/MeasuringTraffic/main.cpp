#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int A[100], B[100];
string X[100];
int before[2], after[2];

int main() {
    ifstream fin ("traffic.in"); 
    ofstream fout ("traffic.out");
    fin >> N;

    for (int i = 0; i < N; i++) 
        fin >> X[i] >> A[i] >> B[i];

    int a = -9999999;
    int b = 9999999;
    for (int i = N-1; i >= 0; i--) {
        if (X[i] == "off") {
            a += A[i];
            b += B[i];
        }
        if (X[i] == "none") {
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (X[i] == "on") {
            a -= B[i]; 
            b -= A[i]; 
            a = max(0, a); 
        }
    }
    fout << a << " " << b << "\n";
    
    a = -9999999;
    b = 9999999;
    for (int i = 0; i < N; i++) {
        if (X[i] == "on") {
            a += A[i];
            b += B[i];
        }
        if (X[i] == "none") {
            a = max(a, A[i]);
            b = min(b, B[i]);
        }
        if (X[i] == "off") {
            a -= B[i]; 
            b -= A[i]; 
            a = max(0, a); 
        }
    }
    fout << a << " " << b << "\n";
    return 0;
}