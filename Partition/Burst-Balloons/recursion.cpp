#include <bits/stdc++.h>
using namespace std;

int dp(int low, int high, vector<int> &nums) {
	if (low > high) return 0;

	int ans = 0;
	for (int i = low; i <= high; i++) {
		ans = max(ans, dp(low, i - 1, nums) + dp(i + 1, high, nums) + nums[low - 1] * nums[i] * nums[high + 1]);
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

	cout << dp(1, n - 2, nums);
	return 0;
}