#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N;
int path[1000001], record[1001];

int main() {
  ifstream fin ("socdist2.in");
  ofstream fout ("socdist2.out");
  fin >> N;
  for (int i = 0; i < 1000001; i++) {
    path[i] = -1;
  }
  for (int i = 0; i < N; i++) {
    int idx, sick;
    fin >> idx >> sick;
    record[i] = idx;
    path[idx-1] = sick;
  }

  sort(record, record+N);

  int maxrad = 99999999;
  for (int i = 1; i < N-1; i++) {
    int rad = 0;
    if ( path[record[i]-1] == 0 ) {
      if (path[record[i-1]-1] == 1) {
        rad = record[i] - record[i-1];
        maxrad = min(rad, maxrad);
      }
      if (path[record[i+1]-1] == 1) {
        rad = record[i+1] - record[i];
        maxrad = min(rad, maxrad);
      }  
    }
  }
  maxrad -= 1;

  int cnt = 0;
  for (int i = 0; i < N-1; i++) {
    if (path[record[i]-1] == 1) {
      cnt++;
      while (i < N-1 && path[record[i+1]-1] == 1 && record[i+1] - record[i] <= maxrad) {
        i++;
      }
    }
  }
  if (path[record[N-1]-1] == 1 && record[N-1] - record[N-2] > maxrad) {
    cnt++;
  }
  fout << cnt << endl;
  return 0;  
}