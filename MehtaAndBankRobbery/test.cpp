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

int primes[11] = {1,2,3,5,7,11,13,17,19,23,29};

int getMaxProfitIterative(P *arr, int w, int n)
{
	int ***dp = new int**[2];
	for (int i = 0; i < 2; i++)
	{
		dp[i] = new int*[n+1];
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = new int[w+1];
			for (int k = 0; k <= w; k++)
			{
				dp[i][j][k] = 0;
			}
			
		}
		
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < w+1; j++)
		{
			dp[0][i][j] = dp[0][i-1][j];
			if(j>=arr[i-1].F)
				dp[0][i][j] = max(dp[0][i][j], dp[0][i-1][j-arr[i-1].F] + arr[i-1].S);
		}
		
	}
	for (int prime = 1; prime <= 10; prime++)
	{
		int p = prime%2;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				dp[p][i][j] = dp[p][i-1][j];
				if(j>= arr[i-1].F)
					dp[p][i][j] = max(dp[p][i][j], max(dp[p][i-1][j-arr[i-1].F] + arr[i-1].S, dp[p^1][i-1][j-arr[i-1].F]+ (arr[i-1].S)*primes[prime]));
			}
			
		}
		
	}
	int ans = dp[0][n][w];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			delete [] dp[i][j];
			
		}
		delete [] dp[i];
		
	}
	delete [] dp;
	return ans;
}
int32_t main(){
	int n,w;
	cin>>n>>w;
	P *arr = new P[n];
	// int **dp = new int*[n+1];
	for (int i = 0; i < n; i++)
	{
		
		int x,p;
		cin>>p>>x;
		arr[i].F = x;
		arr[i].S = p;
	}
	sort(arr, arr + n, [&](P a, P b){
		return a.S < b.S;
	});
	cout<<getMaxProfitIterative(arr, w, n)<<endl;
	return 0;
}