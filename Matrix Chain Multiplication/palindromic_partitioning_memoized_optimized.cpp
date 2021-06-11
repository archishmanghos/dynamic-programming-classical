//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10000;
const double E = 1e-9;

//------------------------------------------------------------------------------
string s;
int dp[N][N];
bool ispalindrome(int l, int h)
{
	while (h > l)
	{
		if (s[l++] != s[h--])
			return false;
	}
	return true;
}
palindromic_partitioning_memoized_optimized(int i, int j)
{
	if (i >= j || ispalindrome(i, j))
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans = INT_MAX, tempans = 0, left = 0, right = 0;
	for (int k = i; k <= j - 1; k++)
	{
		if (dp[i][k] != -1)
			left = dp[i][k];
		else
			left = palindromic_partitioning_memoized_optimized(i, k);
		if (dp[k + 1][j] != -1)
			right = dp[k + 1][j];
		else
			right = palindromic_partitioning_memoized_optimized(k + 1, j);
		tempans = left + right + 1;
		ans = min(ans, tempans);
	}
	return dp[i][j] = ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	memset(dp, -1, sizeof(dp));
	cin >> s;
	cout << palindromic_partitioning_memoized_optimized(0, s.size() - 1);
	return 0;
}
//
//------------------------------------------------------------------------------