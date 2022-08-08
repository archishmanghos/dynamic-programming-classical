#include <bits/stdc++.h>
using namespace std;

int dp(int low, int high, vector<int> &cuts) {
	if (low >= high - 1) return 0;

	int ans = 1e9;
	for (int i = low + 1; i < high; i++) {
		ans = min(ans, dp(low, i, cuts) + dp(i, high, cuts) + cuts[high - 1] - (low ? cuts[low - 1] : 0));
	}

	return ans;
}

int32_t main() {

	int n, c; cin >> n >> c;
	vector<int> cuts(c + 1);
	for (int i = 0; i < c; i++) cin >> cuts[i];
	cuts[c] = n;
	sort(cuts.begin(), cuts.end());

	cout << dp(0, c + 1, cuts);
	return 0;
}