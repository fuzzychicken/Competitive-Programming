#include <bits/stdc++.h>
using namespace std;

long long n;
string s;

char go(long long idx) {
	if (idx < s.size()) {
		return s[idx];
	}
	long long length = s.size();
	while (2*length <= idx) {
		length *= 2;
	}
	if (length == idx) {
		return go(length-1);
	}
	return go(idx-length-1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("cowcode.in","r",stdin);
	//freopen("cowcode.out","w",stdout);
	cin >> s >> n;
	cout << go(n-1) << '\n';
	return 0;
}
