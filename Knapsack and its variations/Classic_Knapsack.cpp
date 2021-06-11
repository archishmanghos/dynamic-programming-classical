//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100000;
const double E = 1e-9;

//------------------------------------------------------------------------------
int weight, n, w[N], val[N];
int knapsack()
{
	int dp[n + 1][weight + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= weight; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else
			{
				if (w[i - 1] <= weight)
					dp[i][j] = max(val[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][weight];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n >> weight;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	cout << knapsack();
	return 0;
}
//
//------------------------------------------------------------------------------