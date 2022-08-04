#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n, INT_MIN);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<int> preCache(n + 1, 0), curCache(n + 1, 0);
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 0; j--) {
			if (i == n) {
				curCache[j] = j == 0 or nums[i - 1] > nums[j - 1];
			} else {
				curCache[j] = preCache[j];
				if (j == 0 or nums[i - 1] > nums[j - 1]) {
					curCache[j] = max(curCache[j], preCache[i] + 1);
				}
			}
		}
		preCache = curCache;
	}

	cout << curCache[0];
	return 0;
}