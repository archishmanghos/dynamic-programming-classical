//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e7 + 7;
const double E = 1e-9;

//------------------------------------------------------------------------------
int n, a[N];
int min_subset_sum(int k)
{
	bool dp[n + 1][k + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i == 0 && j == 0)
				dp[i][j] = true;
			else if (i == 0)
				dp[i][j] = false;
			else if (j == 0)
				dp[i][j] = true;
			else
			{
				if (a[i - 1] <= j)
					dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	vector<int> v;
	for (int i = 0; i <= k / 2; i++)
		if (dp[n][i])
			v.push_back(i);
	int minn = INT_MAX;
	for (int i = 0; i < v.size(); i++)
		minn = k - 2 * v[i];
	return minn;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	cout << min_subset_sum(sum);
	return 0;
}
//
//------------------------------------------------------------------------------