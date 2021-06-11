//Practice
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10000;
const double E = 1e-9;

//------------------------------------------------------------------------------
int solve(int arr[],int i,int j)
{
	int ans=0;
	if(i>j)
		return 0;
	for(int k=i;k<j;k++)
	{
		int tempans=solve(arr,i,k)(+)solve(arr,k+1,j);
		ans=max(ans,tempans);
	}
	return ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	
	return 0;
}
//
//------------------------------------------------------------------------------