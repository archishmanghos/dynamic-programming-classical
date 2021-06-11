//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100000;
const double E = 1e-9;

//------------------------------------------------------------------------------
int lcs(string s1, string s2, int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	if (s1[n - 1] == s2[m - 1])
		return (lcs(s1, s2, n - 1, m - 1) + 1);
	else
		return max(lcs(s1, s2, n, m - 1), lcs(s1, s2, n - 1, m));
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	cout << lcs(s1, s2, n, m);
	return 0;
}
//
//------------------------------------------------------------------------------