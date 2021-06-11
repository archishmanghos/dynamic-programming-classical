//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100000;
const double E = 1e-9;

//------------------------------------------------------------------------------
int a[N], n, k;
bool cntsubsetsum(int k)
{
	bool arr[n + 1][k + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i == 0 && j == 0)
				arr[i][j] = true;
			else if (i == 0)
				arr[i][j] = false;
			else if (j == 0)
				arr[i][j] = true;
			else
			{
				if (a[i - 1] <= j)
					arr[i][j] = arr[i - 1][j] || arr[i - 1][j - a[i - 1]];
				else
					arr[i][j] = arr[i - 1][j];
			}
		}
	}
	return arr[n][k];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << cntsubsetsum(k);
	return 0;
}
//
//------------------------------------------------------------------------------