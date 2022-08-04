#include <bits/stdc++.h>
using namespace std;

int dp(int index, int buy, int n, int fee, vector<int> &prices, vector<vector<int>> &cache) {
	if (index == n - 1) {
		return (buy ? 0 : prices[index] - fee);
	}

	int &profit = cache[index][buy];
	if (profit != -1) return profit;

	if (buy) {
		profit = max(dp(index + 1, 0, n, fee, prices, cache) - prices[index], dp(index + 1, 1, n, fee, prices, cache));
	} else {
		profit = max(dp(index + 1, 1, n, fee, prices, cache) + (prices[index] - fee), dp(index + 1, 0, n, fee, prices, cache));
	}

	return profit;
}

int32_t main() {

	int n, fee; cin >> n >> fee;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) cin >> prices[i];

	vector<vector<int>> cache(n, vector<int>(2, -1));
	cout << dp(0, 1, n, fee, prices, cache);
	return 0;
}