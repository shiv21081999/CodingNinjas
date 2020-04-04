#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mod 1000000007  
const int N = 100005, M = 11;
// int dp[1001][1001];
// int isAvailable(char a , string b , int idx)
// {
	
// 	for (int i = idx; i < b.length(); ++i)
// 	{
// 		if(b[i] == a)
// 		{
// 			// cout<<idx<<" "<<a<<" "<<b[i]<<endl;
// 			return i;
// 		}
// 	}
// 	return -1;
// }

// int solve1(string a , string b, int idx1 , int idx2)
// {
	
// 	if(idx1 == a.length())
// 		return 100000;
// 	if(idx2 >= b.length())
// 		return 1;
// 	if(dp[idx1][idx2]!= -1)
// 		return dp[idx1][idx2];
// 	int x = isAvailable(a[idx1], b , idx2);
// 	// cout<<idx1<<" "<<idx2<<" "<<x<<" "<<a[idx1]<<" "<<b[idx2]<<endl;
// 	// cout<<x<<endl;
// 	if(x == -1)
// 	{
// 		return dp[idx1][idx2] = 1;
// 	}
// 	int ans1 = 1+solve1(a,b,idx1+1,x+1);
// 	int ans2 = solve1(a,b,idx1+1,idx2);
// 	return dp[idx1][idx2] = min(ans1,ans2);
// }
int solve(string a,string b)
{
	int n = a.length();
	int m = b.length();
	int dp[n+1][m+1];
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 1;
	}
	for (int i = 0; i <= m; ++i)
	{
		dp[0][i] = 100000;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char s = a[i-1];
			int k = 0;
			for (k = j-1; k >= 0; --k)
			{
				if(b[k] == s)
					break;
			}
			if(k == -1)
				dp[i][j] = 1;
			else
			{
				dp[i][j] = min(dp[i-1][j], dp[i-1][k]+1);
			}
		}
	}
	return dp[n][m];
}

int32_t main(){
	string a,b;
	cin>>a>>b;
	cout<<solve(a,b)<<endl;
	// for(int i = 0 ; i < 6 ; i++)
	// {
	// 	for( int j = 0 ; j < 6 ; j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}