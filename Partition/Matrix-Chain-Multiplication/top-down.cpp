#include <bits/stdc++.h>
using namespace std;

int dp(int low, int high, vector<int> &arr, vector<vector<int>> &cache) {
	if (low == high) return 0;

	int &ans = cache[low][high];
	if (ans != -1) return ans;

	ans = 1e9;
	for (int i = low; i < high; i++) {
		ans = min(ans, dp(low, i, arr, cache) + dp(i + 1, high, arr, cache) + arr[low - 1] * arr[i] * arr[high]);
	}

	return ans;
}

int32_t main() {

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<vector<int>> cache(n, vector<int>(n, -1));
	cout << dp(1, n - 1, arr, cache);
	return 0;
}