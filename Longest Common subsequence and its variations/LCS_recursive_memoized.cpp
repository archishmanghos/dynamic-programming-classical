//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10000;
const double E = 1e-9;

//------------------------------------------------------------------------------
int dp[N][N];
int lcs_memoized(string s1, string s2, int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	if (dp[m][n] != -1)
		return dp[m][n];
	if (s1[n - 1] == s2[m - 1])
		return dp[m][n] = lcs_memoized(s1, s2, n - 1, m - 1) + 1;
	else
		return dp[m][n] = max(lcs_memoized(s1, s2, n, m - 1), lcs_memoized(s1, s2, n - 1, m));
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	memset(dp, -1, sizeof(dp));
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	cout << lcs_memoized(s1, s2, n, m);
	return 0;
}
//
//------------------------------------------------------------------------------