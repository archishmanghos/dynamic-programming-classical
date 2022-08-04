#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n, INT_MIN);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<int> cache(n, 1);
	int lis = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				cache[i] = max(cache[i], 1 + cache[j]);
			}
		}
		lis = max(lis, cache[i]);
	}

	cout << lis;
	return 0;
}