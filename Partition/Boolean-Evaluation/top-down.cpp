#include <bits/stdc++.h>
using namespace std;

int64_t mul(int64_t a, int64_t b, int mod = 1e9 + 7) {
	return ((a % mod) * (b % mod)) % mod;
}

int64_t add(int64_t a, int64_t b, int mod = 1e9 + 7) {
	return ((a % mod) + (b % mod)) % mod;
}

int getWays(char op, bool wantTrue, int64_t lt, int64_t rt, int64_t lf, int64_t rf) {
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

int dp(int low, int high, bool wantTrue, string &s, vector<vector<vector<int>>> &cache) {
	if (low == high) return (wantTrue ? s[low] == 'T' : s[low] == 'F');

	int &ans = cache[low][high][wantTrue];
	if (ans != -1) return ans;

	ans = 0;
	for (int i = low + 1; i < high; i += 2) {
		int64_t leftWantsTrue = dp(low, i - 1, 1, s, cache);
		int64_t rightWantsTrue = dp(i + 1, high, 1, s, cache);
		int64_t leftWantsFalse = dp(low, i - 1, 0, s, cache);
		int64_t rightWantsFalse = dp(i + 1, high, 0, s, cache);
		ans = add(ans, getWays(s[i], wantTrue, leftWantsTrue, rightWantsTrue, leftWantsFalse, rightWantsFalse));
	}

	return ans;
}

int32_t main() {

	string s; cin >> s;
	int n = s.size();

	vector<vector<vector<int>>> cache(n, vector<vector<int>>(n, vector<int>(2, -1)));
	cout << dp(0, n - 1, 1, s, cache);
	return 0;
}