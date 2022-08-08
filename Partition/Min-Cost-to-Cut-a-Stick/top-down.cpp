#include <bits/stdc++.h>
using namespace std;

int dp(int low, int high, vector<int> &cuts, vector<vector<int>> &cache) {
	if (low >= high - 1) return 0;

	int &ans = cache[low][high];
	if (ans != -1) return ans;

	ans = 1e9;
	for (int i = low + 1; i < high; i++) {
		ans = min(ans, dp(low, i, cuts, cache) + dp(i, high, cuts, cache) + cuts[high - 1] - (low ? cuts[low - 1] : 0));
	}

	return ans;
}

int32_t main() {

	int n, c; cin >> n >> c;
	vector<int> cuts(c + 1);
	for (int i = 0; i < c; i++) cin >> cuts[i];
	cuts[c] = n;
	sort(cuts.begin(), cuts.end());

	vector<vector<int>> cache(c, vector<int>(c + 2, -1));
	cout << dp(0, c + 1, cuts, cache);
	return 0;
}