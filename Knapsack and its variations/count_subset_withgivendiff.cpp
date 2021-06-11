//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e7 + 7;
const double E = 1e-9;

//------------------------------------------------------------------------------
int n, diff, a[N];
int count_subset_withgivendiff(int k)
{
	int dp[n + 1][k + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i == 0 && j == 0)
				dp[i][j] = 1;
			else if (i == 0)
				dp[i][j] = 0;
			else if (j == 0)
				dp[i][j] = 1;
			else
			{
				if (a[i - 1] <= j)
					dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][k];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n >> diff;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int k = (sum - diff) / 2;
	cout << count_subset_withgivendiff(k);
	return 0;
}
//
//------------------------------------------------------------------------------