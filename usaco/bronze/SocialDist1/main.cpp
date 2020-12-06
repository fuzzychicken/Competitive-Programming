#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int N, gapstart; 
string s;

int LargestGap(string s) {
  int cnt = 0;
  int maxgap = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      cnt++;     
      if (maxgap < cnt) {
        maxgap = cnt;
        gapstart = i - cnt;
      }     
    }
    else {
      cnt = 0;
    }
  }
  return maxgap + 1;
}

int SmallestGap(string s) {
  int mingap = 1000000000;
  int current_start = -1;
  for (int i = 0; i < s.length(); i++) 
    if (s[i] == '1') {
      if (current_start != -1 && i-current_start < mingap) {
        mingap = i-current_start;
      }
      current_start = i;
    }
  return mingap;
}

int main() {
  ifstream fin ("socdist1.in");
  ofstream fout ("socdist1.out");

  fin >> N >> s;
  int largestgap = LargestGap(s);
  int best = 0;
  
  if (largestgap > 1) {
    string modified = s;
    for (int i = 0; i < 2; i++) {
      int x = LargestGap(modified);
      modified[gapstart + x/2] = '1';
    }
    best = max(best, SmallestGap(modified));
  }

  if (s[0] == '0' && s[N-1] == '0') {
    string modified = s;
    modified[0] = '1';
    modified[N-1] = '1';
    best = max(best, SmallestGap(modified));
  }

  if (s[0] == '0') {
    string modified = s;
    modified[0] = '1';
    int x = LargestGap(modified);
    modified[gapstart + x/2] = '1';
    best = max(best, SmallestGap(modified));
  }

  if (s[N-1] == '0') {
    string modified = s;
    modified[N-1] = '1';
    int x = LargestGap(modified);
    modified[gapstart + x/2] = '1';
    best = max(best, SmallestGap(modified));
  }

  if (largestgap > 2) {
    string modified = s;
    int x = LargestGap(modified);
    modified[gapstart + x/3] = '1';
    modified[gapstart + x*2/3] = '1';
    best = max(best, SmallestGap(modified));
  }
  fout << best << endl;
  return 0;
}