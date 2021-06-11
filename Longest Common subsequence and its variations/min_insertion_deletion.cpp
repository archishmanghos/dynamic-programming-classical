//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10000;
const double E = 1e-9;

//------------------------------------------------------------------------------
string s1, s2;
int n, m;
pair<int, int> min_insertion_deletion()
{
	pair<int, int> ans;
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= m; i++)
		dp[0][i] = 0;
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
	ans.first = n - dp[n][m];
	ans.second = m - dp[n][m];
	return ans;
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
	pair<int, int> ans;
	ans = min_insertion_deletion();
	cout << ans.first << " " << ans.second;
	return 0;
}
//
//------------------------------------------------------------------------------