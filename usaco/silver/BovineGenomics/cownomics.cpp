#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
int plain[500][50], spotty[500][50];

void check_triple(int i, int j, int k) {
	set<int> plain_nums;
	for (int x = 0; x < n; x++) {
		// multiple by these nums to make sure every set is unique
		// even if they have same chars, the order matters!!
		plain_nums.insert(plain[x][i]*16 + plain[x][j]*3 + plain[x][k]*15);
	}
	for (int x = 0; x < n; x++) {
		int to_find = spotty[x][i]*16 + spotty[x][j]*3 + spotty[x][k]*15;
		if (plain_nums.find(to_find) != plain_nums.end()) {
			return;
		}
	}
	cnt++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'A') spotty[i][j] = 1;
			else if (str[j] == 'G') spotty[i][j] = 10;
			else if (str[j] == 'C') spotty[i][j] = 43;
			else if (str[j] == 'T') spotty[i][j] = 18;
		}
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'A') plain[i][j] = 1;
			else if (str[j] == 'G') plain[i][j] = 10;
			else if (str[j] == 'C') plain[i][j] = 43;
			else if (str[j] == 'T') plain[i][j] = 18;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			for (int k = j+1; k < m; k++) {
				check_triple(i, j, k);
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
