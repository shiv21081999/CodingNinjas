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
#define MAXN 16
int solve(int arr[][MAXN], int n)
{
	int *dp = new int[1<<n];
	for (int i = 0; i < (1<<n); i++)
	{
		dp[i] = 0;
	}
	dp[0] = 1;
	for (int mask = 0; mask < (1<<n)-1; mask++)
	{
		int temp = mask;
		int k=0;
		while(temp > 0)
		{
			if(temp%2 == 1)
				k++;
			temp = temp/2;
		}
		for (int  j = 0; j < n; j++)
		{
			if(!(mask&(1<<j)) && arr[k][j] != 0)
			{
				dp[mask|1<<j] += dp[mask];
				
			}
		}
		
	}
	delete [] dp;
	return dp[(1<<n)-1];
}
int32_t main(){
	int n;
	cin>>n;
	int arr[MAXN][MAXN];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>arr[i][j];
		}
		
	}
	
	int ans = solve(arr, n);
	cout<<ans<<endl;
	return 0;
}