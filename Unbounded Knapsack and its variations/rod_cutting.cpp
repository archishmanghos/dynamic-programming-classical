//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100000;
const double E = 1e-9;

//------------------------------------------------------------------------------
int n, len[N], price[N];
int rod_cutting()
{
	int dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else
			{
				if (len[i - 1] <= j)
					dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]], dp[i - 1][j]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][n];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n;
	for (int i = 1; i <= n; i++)
		len[i - 1] = i;
	for (int i = 0; i < n; i++)
		cin >> price[i];
	cout << rod_cutting();
	return 0;
}
//
//------------------------------------------------------------------------------