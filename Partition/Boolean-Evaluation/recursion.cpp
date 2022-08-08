#include <bits/stdc++.h>
using namespace std;

int mul(int a, int b, int mod = 1e9 + 7) {
	return ((a % mod) * (b % mod)) % mod;
}

int add(int a, int b, int mod = 1e9 + 7) {
	return ((a % mod) + (b % mod)) % mod;
}

int getWays(char op, bool wantTrue, int lt, int rt, int lf, int rf) {
	if (op == '&') {
		if (wantTrue) return mul(lt, rt);
		return add(mul(lf, rf), add(mul(lt, rf), mul(lf, rt)));
	} else if (op == '|') {
		if (wantTrue) return add(mul(lt, rt), add(mul(lt, rf), mul(lf, rt)));
		return mul(lf, rf);
	} else {
		if (wantTrue) return add(mul(lt, rf), mul(lf, rt));
		return add(mul(lf, rf), mul(lt, rt));
	}

	return 0;
}

int dp(int low, int high, bool wantTrue, string &s) {
	if (low == high) return (wantTrue ? s[low] == 'T' : s[low] == 'F');

	int ans = 0;
	for (int i = low + 1; i < high; i += 2) {
		int leftWantsTrue = dp(low, i - 1, 1, s);
		int rightWantsTrue = dp(i + 1, high, 1, s);
		int leftWantsFalse = dp(low, i - 1, 0, s);
		int rightWantsFalse = dp(i + 1, high, 0, s);
		ans = add(ans, getWays(s[i], wantTrue, leftWantsTrue, rightWantsTrue, leftWantsFalse, rightWantsFalse));
	}

	return ans;
}

int32_t main() {

	string s; cin >> s;
	int n = s.size();

	cout << dp(0, n - 1, 1, s);
	return 0;
}