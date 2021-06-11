//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10000;
const double E = 1e-9;

//------------------------------------------------------------------------------
int n, a[N], dp[N][N];
min_cost_mcm(int i, int j)
{
	if (i >= j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++)
	{
		int tempans = min_cost_mcm(i, k) + min_cost_mcm(k + 1, j) + (a[i - 1] * a[k] * a[j]);
		ans = min(ans, tempans);
	}
	return dp[i][j]=ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << min_cost_mcm(1, n - 1);
	return 0;
}
//
//------------------------------------------------------------------------------