#include <bits/stdc++.h>
using namespace std;

int dp(int index, int prevIndex, int n, vector<int> &nums) {
	if (index == n) {
		return nums[index - 1] > nums[prevIndex - 1] ? 1 : 0;
	}

	int length = dp(index + 1, prevIndex, n, nums);
	if (prevIndex == 0 or nums[index - 1] > nums[prevIndex - 1]) {
		length = max(length, dp(index + 1, index, n, nums) + 1);
	}

	return length;
}

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n, INT_MIN);
	for (int i = 0; i < n; i++) cin >> nums[i];

	cout << dp(1, 0, n, nums);
	return 0;
}