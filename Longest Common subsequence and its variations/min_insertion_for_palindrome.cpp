//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10000;
const double E = 1e-9;

//------------------------------------------------------------------------------
string s1, s2;
int n;
int min_insertion_for_palindrome()
{
	int dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= n; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return n - dp[n][n];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());
	n = s1.size();
	cout << min_insertion_for_palindrome();
	return 0;
}
//
//------------------------------------------------------------------------------