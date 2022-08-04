#include <bits/stdc++.h>
using namespace std;

int dp(int index, int buy, int n, int fee, vector<int> &prices) {
	if (index == n - 1) {
		return (buy ? 0 : prices[index] - fee);
	}

	int profit;
	if (buy) {
		profit = max(dp(index + 1, 0, n, fee, prices) - prices[index], dp(index + 1, 1, n, fee, prices));
	} else {
		profit = max(dp(index + 1, 1, n, fee, prices) + (prices[index] - fee), dp(index + 1, 0, n, fee, prices));
	}

	return profit;
}

int32_t main() {

	int n, fee; cin >> n >> fee;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) cin >> prices[i];

	cout << dp(0, 1, n, fee, prices);
	return 0;
}