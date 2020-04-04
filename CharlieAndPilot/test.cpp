#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int n = 0;
int dp[10001][5002];
int getMinMoney(int ass[] , int cap[], int a , int c, int curr)
{
	if(dp[curr][a] != 0)
		return dp[curr][a];
	if(a == n/2)
	{
		int ans = 0 , x = curr;
		while(x < n) {
		    ans += cap[x++];
		}
		return dp[curr][a] = ans;
	}
	if(a==c)
	{
		return dp[curr][a] = ass[curr] + getMinMoney(ass,cap,a+1,c,curr+1);
	}
	if(a > c)
		return dp[curr][a] =  min(ass[curr] + getMinMoney(ass,cap, a+1,c,curr+1),cap[curr] + getMinMoney(ass,cap,a,c+1,curr+1));
	
	else return 0;
}
int32_t main(){
	cin>>n;
	int *ass = new int[n];
	int *cap = new int[n];
	for (int i = 0; i < n; i++)
	{
		int x , y;
		cin>>x>>y;
		cap[i] = x;
		ass[i] = y;
	}
	cout<<getMinMoney(ass, cap, 0,0,0)<<endl;
}