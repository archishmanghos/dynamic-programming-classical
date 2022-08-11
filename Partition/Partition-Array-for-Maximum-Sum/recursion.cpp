#include <bits/stdc++.h>
using namespace std;

int dp(int index, int k, int n, vector<int> &arr) {
	if (index == n) return 0;

	int ans = 0, maxElement = 0;
	for (int i = index; i < min(index + k, n); i++) {
		maxElement = max(maxElement, arr[i]);
		ans = max(ans, dp(i + 1, k, n, arr) + (i - index + 1) * maxElement);
	}

	return ans;
}

int32_t main() {

	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (int &i : arr) cin >> i;

	cout << dp(0, k, n, arr);
	return 0;
}