//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10000;
const double E = 1e-9;

//------------------------------------------------------------------------------
string s;
bool ispalindrome(int l,int h)
{
	while (h > l)
	{
		if (s[l++] != s[h--])
			return false;
	}
	return true;
}
palindromic_partitioning(int i, int j)
{
	if (i >= j || ispalindrome(i,j))
		return 0;
	int ans = INT_MAX, tempans = 0;
	for (int k = i; k <= j - 1; k++)
	{
		tempans = palindromic_partitioning(i, k) + palindromic_partitioning(k + 1, j) + 1;
		ans = min(ans, tempans);
	}
	return ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> s;
	cout << palindromic_partitioning(0, s.size() - 1);
	return 0;
}
//
//------------------------------------------------------------------------------