#include <bits/stdc++.h>
using namespace std;

int dp(int index, int prevIndex, int n, vector<int> &nums, vector<vector<int>> &cache) {
	if (index == n) {
		return nums[index - 1] > nums[prevIndex - 1];
	}

	int &length = cache[index][prevIndex];
	if (length != -1) return length;

	length = dp(index + 1, prevIndex, n, nums, cache);
	if (prevIndex == 0 or  nums[index - 1] > nums[prevIndex - 1]) {
		length = max(length, dp(index + 1, index, n, nums, cache) + 1);
	}

	return length;
}

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n, INT_MIN);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<vector<int>> cache(n, vector<int>(n, -1));
	cout << dp(1, 0, n, nums, cache);
	return 0;
}