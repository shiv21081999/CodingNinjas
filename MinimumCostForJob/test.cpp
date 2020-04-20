#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 1000000007;

int getAns(int **arr, int n, int p, int mask, int *dp)
{
	if(p >= n)
		return 0;
	if(dp[mask] != INT_MAX)
		return dp[mask];
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if(!(mask&(1<<i)))
		{
			int ans = getAns(arr, n, p+1, mask | (1<<i), dp) + arr[p][i];
			if(ans < min)
				min = ans;
		}
	}
	dp[mask] = min;
	return min;
}

int32_t main(){
	int n;
	cin>>n;
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin>>arr[i][j];
		}
		
	}
	int *dp = new int[1<<n];
	for (int i = 0; i < (1<<n); i++)
	{
		dp[i] = INT_MAX;
	}
	
	int ans = getAns(arr, n, 0, 0, dp);
	cout<<ans<<endl;
	for (int i = 0; i < n; i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
	delete [] dp;
	return 0;
}