#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string s, ans;
	getline(cin, s);
	int p1=0, p2=1;
	while (p2 < s.size()) {
		if (s[p2] == s[p1] && s[p2+1] != s[p1]) {
			
		} else {
			ans += s[p1];
		}
		p1++, p2++;
	}
	cout << ans << '\n';
	return 0;
}