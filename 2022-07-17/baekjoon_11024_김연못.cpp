#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int N; 
	cin >> N; 
	cin.ignore();
	while (N--) {
		string s; 
		getline(cin, s);
		int ans = 0;
		for (int i = 0, t = 0; i <= s.size(); i++) {
			if (i < s.size() && s[i] != ' ') t = 10 * t + s[i] - '0';
			else ans += t, t = 0;
		}
		cout << ans << '\n';
	}
}