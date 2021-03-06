#include <bits/stdc++.h>
using namespace std;

int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  char fence[n];
  cin >> fence;
  int a[n];
  int pref[n];
  for (int i = 0; i < n; i++) {
    a[i] = fence[i]-'A'+1; 
  }
  pref[0] = 1;
  int pref2[n];
  for (int i = 1; i < n; i++) {
    int d = a[i] - a[i-1];
    if (d > 0) d = 1;
    if (d < 0) d = 0;
    pref[i] = d;
  }
  partial_sum(pref, pref+n, pref2);
  /* for (int i = 0; i < n; i++) { */
  /*   cout << pref[i] << endl; */
  /* } */
  for (int i = 0; i < q; i++) {
    int left, right;
    cin >> left >> right;
    left--, right--;
    int sum1, sum2;
    if (left != 0) {
      sum1 = pref2[left-1] - 0;
    } else {
      sum1 = 0;
    }
    if (right != n-1) {
      sum2 = abs(pref2[n-1] - pref2[right+1]) + 1;
      if (a[right+1] > a[right+2]) {
        sum2++;
      }
    } else {
      sum2 = 0;
    }
    cout << sum1+sum2 << endl;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}