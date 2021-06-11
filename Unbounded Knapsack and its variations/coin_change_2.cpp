//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100000;
const double E = 1e-9;

//------------------------------------------------------------------------------
int n, coin[N], sum;
int coin_change_2()
{
	int dp[n + 1][sum + 1];
	for (int i = 0; i <= sum; i++)
		dp[0][i] = INT_MAX - 1;
	for (int i = 1; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= sum; i++)
		dp[1][i] = (i % coin[0] ? INT_MAX - 1 : (i / coin[0]));
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (coin[i - 1] <= j)
				dp[i][j] = min(dp[i - 1][j], dp[i][j - coin[i - 1]] + 1);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][sum];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n >> sum;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	cout << coin_change_2();
	return 0;
}
//
//------------------------------------------------------------------------------