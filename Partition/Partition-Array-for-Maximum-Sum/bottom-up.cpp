#include <bits/stdc++.h>
using namespace std;

int dp(int index, int k, int n, vector<int> &arr, vector<int> &cache) {
	if (index == n) return 0;

	int &ans = cache[index], maxElement;
	if (ans != -1) return ans;

	ans = 0, maxElement = 0;
	for (int i = index; i < min(index + k, n); i++) {
		maxElement = max(maxElement, arr[i]);
		ans = max(ans, dp(i + 1, k, n, arr, cache) + (i - index + 1) * maxElement);
	}

	return ans;
}

int32_t main() {

	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (int &i : arr) cin >> i;

	vector<int> cache(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		int maxElement = 0;
		for (int j = i; j < min(i + k, n); j++) {
			maxElement = max(maxElement, arr[j]);
			cache[i] = max(cache[i], cache[j + 1] + (j - i + 1) * maxElement);
		}
	}

	cout << cache[0];
	return 0;
}