//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10000;
const double E = 1e-9;

//------------------------------------------------------------------------------
string s1, s2;
int n, m;
int lcs_topdown()
{
	int dp[n + 1][m + 1];
	for (int i = 0; i <= m; i++)
		dp[0][i] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> s1 >> s2;
	n = s1.size();
	m = s2.size();
	cout << lcs_topdown();
	return 0;
}
//
//------------------------------------------------------------------------------