#include <bits/stdc++.h>
using namespace std;

bool checkPal(int l, int r, string &s) {
	while (l < r) {
		if (s[l++] != s[r--]) return false;
	}

	return true;
}

int dp(int index, int n, string &s) {
	if (index == n) return 0;

	int ans = INT_MAX;
	for (int i = index; i < n; i++) {
		if (checkPal(index, i, s)) {
			ans = min(ans, dp(i + 1, n, s) + 1);
		}
	}

	return ans;
}

int32_t main() {

	string s; cin >> s;
	int n = s.size();

	cout << dp(0, n, s) - 1;
	return 0;
}