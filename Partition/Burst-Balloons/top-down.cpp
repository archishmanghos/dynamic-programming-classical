#include <bits/stdc++.h>
using namespace std;

int dp(int low, int high, vector<int> &nums, vector<vector<int>> &cache) {
	if (low > high) return 0;

	int &ans = cache[low][high];
	if (ans != -1) return ans;

	for (int i = low; i <= high; i++) {
		ans = max(ans, dp(low, i - 1, nums, cache) + dp(i + 1, high, nums, cache) + nums[low - 1] * nums[i] * nums[high + 1]);
	}

	return ans;
}

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	n += 2;

	vector<vector<int>> cache(n, vector<int>(n, -1));
	cout << dp(1, n - 2, nums, cache);
	return 0;
}